set( ANTLR4_SOURCE_DIR
	${PROJECT_SOURCE_DIR}/third_party/antlr4/runtime/Cpp/runtime/src
)

set( IFD_GENERATED_SOURCES
	${PROJECT_SOURCE_DIR}/src/generated/IFDBaseVisitor.cpp
	${PROJECT_SOURCE_DIR}/src/generated/IFDVisitor.cpp
	${PROJECT_SOURCE_DIR}/src/generated/IFDParser.cpp
	${PROJECT_SOURCE_DIR}/src/generated/IFDLexer.cpp
)

set( OBJ_GENERATED_SOURCES
	${PROJECT_SOURCE_DIR}/src/generated/OBJBaseVisitor.cpp
	${PROJECT_SOURCE_DIR}/src/generated/OBJVisitor.cpp
	${PROJECT_SOURCE_DIR}/src/generated/OBJParser.cpp
	${PROJECT_SOURCE_DIR}/src/generated/OBJLexer.cpp
)

foreach( src_file ${IFD_GENERATED_SOURCES} )
	set_source_files_properties(
		${src_file} PROPERTIES GENERATED TRUE
	)
endforeach( src_file ${IFD_GENERATED_SOURCES} )

add_custom_command( OUTPUT ${IFD_GENERATED_SOURCES}
	COMMAND 
	${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/src/generated/
	
	COMMAND
	"${Java_JAVA_EXECUTABLE}" -jar ${ANTLR4CPP_JAR_LOCATION} -Werror -Dlanguage=Cpp -listener -visitor -o ${PROJECT_SOURCE_DIR}/src/generated/ -package shout ${PROJECT_SOURCE_DIR}/src/shout_lib/IFD.g4
)

foreach( src_file ${OBJ_GENERATED_SOURCES} )
	set_source_files_properties(
		${src_file} PROPERTIES GENERATED TRUE
	)
endforeach( src_file ${OBJ_GENERATED_SOURCES} )

add_custom_command( OUTPUT ${OBJ_GENERATED_SOURCES}
	COMMAND 
	${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/src/generated/
	
  COMMAND
  "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR4CPP_JAR_LOCATION} -Werror -Dlanguage=Cpp -listener -visitor -o ${PROJECT_SOURCE_DIR}/src/generated/ -package shout ${PROJECT_SOURCE_DIR}/src/shout_lib/OBJ.g4
)

add_custom_target( GenerateParser DEPENDS ${IFD_GENERATED_SOURCES} ${OBJ_GENERATED_SOURCES} )

include_directories(
	${ANTLR4_SOURCE_DIR}
	${ANTLR4_SOURCE_DIR}/misc
	${ANTLR4_SOURCE_DIR}/atn
	${ANTLR4_SOURCE_DIR}/dfa
	${ANTLR4_SOURCE_DIR}/tree
	${ANTLR4_SOURCE_DIR}/support
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/src/generated
)

set( SOURCES
	./utils.cpp
	./SCN/SCN_Scene.cpp
	./SCN/SCN_IORegistry.cpp
	./SCN/SCN_IOTranslator.cpp
	./SCN/SCN_OBJTranslator.cpp
	./SCN/SCN_IFDTranslator.cpp
	./display.cpp
	./renderer.cpp
	./renderer_opengl.cpp
	${GENERATED_SOURCES}
)

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set (flags_1 "-Wno-overloaded-virtual")
else()
  set (flags_1 "-MP /wd4251")
endif()

foreach( src_file ${GENERATED_SOURCES} )
	set_source_files_properties(
		${src_file} PROPERTIES COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
	)
endforeach( src_file ${GENERATED_SOURCES} )

# we will use static libs
add_definitions(-DBOOST_LOG_DYN_LINK)

# find boost libs
find_package( Boost COMPONENTS program_options log REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} )

include_directories ( /System/Library/Frameworks )

# find opengl libs 
find_library(OpenGL_LIBRARY OpenGL )

find_package( Threads )


add_library ( shout_lib SHARED ${SOURCES} )
target_link_libraries( shout_lib antlr4_static Boost::log Threads::Threads ${OpenGL_LIBRARY} )
set_target_properties( shout_lib PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS ON
	OUTPUT_NAME "shout"
)

add_dependencies( shout_lib GenerateParser )

if(APPLE)
	file(GLOB dist_lib_files "${PROJECT_SOURCE_DIR}/dist/macos/*")
	install( FILES
		${dist_lib_files} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	)
endif()

install(TARGETS shout_lib
	RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)