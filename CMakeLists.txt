CMAKE_MINIMUM_REQUIRED( VERSION 3.5 )

PROJECT( Shout )

LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

SET( CMAKE_INSTALL_PREFIX /opt/shout )

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
  #SET(CMAKE_BUILD_TYPE "RELEASE")
  #SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
  #SET(CMAKE_BUILD_TYPE "MINSIZEREL")
ENDIF()

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

# set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/third_party/antlr-4.7.1-complete.jar)

if (MSVC)
	ADD_DEFINITIONS(/W3)
elseif (UNIX) #(CMAKE_COMPILER_IS_GNUCXX)
	ADD_DEFINITIONS(-Wall -pedantic)
else ()
	MESSAGE(FATAL_ERROR "CMakeLists.txt has not been tested/written for your compiler.")
endif ()

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

include_directories( 
	${CMAKE_CURRENT_SOURCE_DIR}/include 
	${CMAKE_CURRENT_SOURCE_DIR}/third_party
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/include 
)

add_subdirectory( third_party/hougeo )
add_subdirectory( third_party/antlr4/runtime/Cpp )
add_subdirectory( src/shout_lib )
add_subdirectory( src/shout_cmd )
