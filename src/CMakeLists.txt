set( GENERATED_SOURCES
	${PROJECT_SOURCE_DIR}/generated/IFDBaseVisitor.cpp
	${PROJECT_SOURCE_DIR}/generated/IFDVisitor.cpp
	${PROJECT_SOURCE_DIR}/generated/IFDParser.cpp
	${PROJECT_SOURCE_DIR}/generated/IFDLexer.cpp
)

foreach( src_file ${GENERATED_SOURCES} )
	set_source_files_properties(
		${src_file} PROPERTIES GENERATED TRUE
	)
endforeach( src_file ${GENERATED_SOURCES} )

add_custom_target( GenerateParser DEPENDS ${GENERATED_SOURCES} )
add_custom_command( OUTPUT ${GENERATED_SOURCES}
	COMMAND 
	${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/generatedZ/
	
	COMMAND
	"${Java_JAVA_EXECUTABLE}" -jar ${ANTLR4CPP_JAR_LOCATION} -Werror -Dlanguage=Cpp -listener -visitor -o ${PROJECT_SOURCE_DIR}/generated/ -package shout ${PROJECT_SOURCE_DIR}/src/IFD.g4
)

include_directories(
	${PROJECT_SOURCE_DIR}/runtime/src
	${PROJECT_SOURCE_DIR}/runtime/src/misc
	${PROJECT_SOURCE_DIR}/runtime/src/atn
	${PROJECT_SOURCE_DIR}/runtime/src/dfa
	${PROJECT_SOURCE_DIR}/runtime/src/tree
	${PROJECT_SOURCE_DIR}/runtime/src/support
	${PROJECT_SOURCE_DIR}/generated
)

set( SOURCES
	./shout.cpp
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

find_package( Threads )

add_executable ( shout ${SOURCES} )
set_target_properties( shout PROPERTIES OUTPUT_NAME "shout" )

add_dependencies( shout GenerateParser )

if(APPLE)
  target_link_libraries(shout "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.dylib")
elseif(UNIX)
  target_link_libraries(shout "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so")
endif()  
 
target_link_libraries( shout antlr4_static Boost::program_options Boost::log Threads::Threads )

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
add_custom_command(TARGET shout POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so"
  $<TARGET_FILE_DIR:shout>)
endif()

if(APPLE)
add_custom_command(TARGET shout POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.dylib"
  $<TARGET_FILE_DIR:shout>)
endif()

install(TARGETS shout DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)