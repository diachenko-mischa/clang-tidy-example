cmake_minimum_required(VERSION 3.14)
project(my_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
  OVERRIDE_FIND_PACKAGE
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


FetchContent_Declare(
    SQLite3
  GIT_REPOSITORY https://github.com/ClickHouse/sqlite-amalgamation.git
  GIT_TAG master
  OVERRIDE_FIND_PACKAGE
)

FetchContent_MakeAvailable(googletest SQLite3)

find_package(SQLite3 REQUIRED CONFIG)

set(CMAKE_CXX_STANDARD 20)
add_executable(main main.cpp)
target_link_libraries(main SQLite3 GTest::gtest_main)
target_compile_options(main PRIVATE --coverage)
target_link_options(main PRIVATE --coverage)
