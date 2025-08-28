cmake_minimum_required(VERSION 3.10)
project(MyCurlProgram)

find_package(CURL REQUIRED)

add_executable(curl_get_demo1 curl_get_demo1.cc)

target_include_directories(curl_get_demo1 PRIVATE ${CURL_INCLUDE_DIRS})
target_link_libraries(curl_get_demo1 PRIVATE ${CURL_LIBRARIES})
