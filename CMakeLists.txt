cmake_minimum_required(VERSION 3.5)
project(learn_boost)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost REQUIRED program_options)

include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES program_options.cpp)
add_executable(learn_boost ${SOURCE_FILES})

target_link_libraries(learn_boost ${Boost_LIBRARIES})