set( ANTLR4_SOURCE_DIR
	${PROJECT_SOURCE_DIR}/third_party/antlr4/runtime/Cpp/runtime/src
)

set( GENERATED_SOURCES
	${PROJECT_SOURCE_DIR}/src/generated/IFDBaseVisitor.cpp
	${PROJECT_SOURCE_DIR}/src/generated/IFDVisitor.cpp
	${PROJECT_SOURCE_DIR}/src/generated/IFDParser.cpp
	${PROJECT_SOURCE_DIR}/src/generated/IFDLexer.cpp
)

foreach( src_file ${GENERATED_SOURCES} )
	set_source_files_properties(
		${src_file} PROPERTIES GENERATED TRUE
	)
endforeach( src_file ${GENERATED_SOURCES} )

add_custom_target( GenerateParser DEPENDS ${GENERATED_SOURCES} )
add_custom_command( OUTPUT ${GENERATED_SOURCES}
	COMMAND 
	${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/src/generated/
	
	COMMAND
	"${Java_JAVA_EXECUTABLE}" -jar ${ANTLR4CPP_JAR_LOCATION} -Werror -Dlanguage=Cpp -listener -visitor -o ${PROJECT_SOURCE_DIR}/src/generated/ -package shout ${PROJECT_SOURCE_DIR}/src/IFD.g4
)

include_directories(
	${ANTLR4_SOURCE_DIR}
	${ANTLR4_SOURCE_DIR}/misc
	${ANTLR4_SOURCE_DIR}/atn
	${ANTLR4_SOURCE_DIR}/dfa
	${ANTLR4_SOURCE_DIR}/tree
	${ANTLR4_SOURCE_DIR}/support
	${PROJECT_SOURCE_DIR}/src/generated
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

#link_directories(
#	${PROJECT_SOURCE_DIR}/third_party/antlr/lib/
#)

add_executable ( shout ${SOURCES} )
set_target_properties( shout PROPERTIES OUTPUT_NAME "shout" )

add_dependencies( shout GenerateParser )
 
target_link_libraries( shout antlr4_static Boost::program_options Boost::log Threads::Threads )

install(TARGETS shout 
	RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)