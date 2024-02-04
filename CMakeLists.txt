cmake_minimum_required(VERSION 3.28)
project(flow-parser)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG 456574145cf71a5375777cab58453acfd92a920b
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost)
find_package(fmt)

include_directories(include ${Boost_INCLUDE_DIRS} ${fmt_INCLUDE_DIRS})
add_executable(flow-parser
        src/main.cpp
        src/query.cpp
        src/parser.cpp)
target_link_libraries(flow-parser ${Boost_LIBRARIES} fmt::fmt)

enable_testing()

add_executable(
        parser_test
        src/query.cpp
        src/parser.cpp
        test/parser-select-test.cpp
)
target_link_libraries(
        parser_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(parser_test)