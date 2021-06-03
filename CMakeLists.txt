cmake_minimum_required(VERSION 3.10)
project(mp4)

set (CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE MP4_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(mp4_src ${MP4_SRC})
target_include_directories(mp4_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(mp4 ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(mp4 mp4_src)

file(GLOB_RECURSE MP4_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${MP4_TEST_SRC})
target_link_libraries(tests mp4_src)
target_link_libraries(tests ${CONAN_LIBS})