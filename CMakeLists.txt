cmake_minimum_required(VERSION 3.5)


project(Lesson_1 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra" )

add_executable(mainApp main.cpp lib.cpp)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

include_directories(${Boost_INCLUDE_DIRS})

find_package( Boost COMPONENTS unit_test_framework REQUIRED )

add_executable(tests version_test.cpp lib.cpp   )

include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries( tests ${Boost_LIBRARIES} )

find_package( Boost COMPONENTS unit_test_framework REQUIRED )

set_target_properties(tests PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

install(TARGETS mainApp RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT yellow_coffee@mail.com)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()
add_test(mainApp_tests tests)
