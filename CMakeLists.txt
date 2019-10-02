cmake_minimum_required(VERSION 3.5)

project(Lesson_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(mainApp main.cpp lib.cpp)

include_directories(${Boost_INCLUDE_DIRS})

find_package( Boost COMPONENTS unit_test_framework REQUIRED )

target_link_libraries( mainApp ${Boost_LIBRARIES} )

#set_target_properties(Lesson_1 PROPERTIES
#    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#)

enable_testing()
add_test(helloworld_tests test_version)


#add_executable(tests version_test.cpp lib.cpp   )

#include_directories(${Boost_INCLUDE_DIRS})
#target_link_libraries( tests ${Boost_LIBRARIES} )

#find_package( Boost COMPONENTS unit_test_framework REQUIRED )

#set_target_properties(tests PROPERTIES
#    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#)

