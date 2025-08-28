cmake_minimum_required(VERSION 3.12)
project(HttpServerExample)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED COMPONENTS system)

# 添加pthread库
find_package(Threads REQUIRED)

add_executable(HttpServerExample server.cc)

target_include_directories(HttpServerExample PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(HttpServerExample PRIVATE ${Boost_LIBRARIES} Threads::Threads)
