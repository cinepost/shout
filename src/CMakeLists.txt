set(SOURCES 
	./shout.cpp
)

# we will use static libs
add_definitions(-DBOOST_LOG_DYN_LINK)

# find boost libs
find_package( Boost COMPONENTS program_options log REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} )

find_package(Threads)

add_executable (shout ${SOURCES} )
set_target_properties(shout PROPERTIES OUTPUT_NAME "shout")
 
target_link_libraries( shout Boost::program_options Boost::log Threads::Threads )

install(TARGETS shout DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)