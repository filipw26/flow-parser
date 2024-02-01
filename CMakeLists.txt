cmake_minimum_required(VERSION 3.28)
project(flow-parser)

set(CMAKE_CXX_STANDARD 23)

#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost)
find_package(fmt)

include_directories(${Boost_INCLUDE_DIRS} ${fmt_INCLUDE_DIRS})
add_executable(flow-parser src/main.cpp src/query.cpp)
target_link_libraries(flow-parser ${Boost_LIBRARIES} fmt::fmt)