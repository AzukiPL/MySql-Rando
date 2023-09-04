cmake_minimum_required(VERSION 3.0.0)
project(Randomizer VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Randomizer main.cpp MyApp.cpp MyApp.hpp DirCheck.hpp MethodProcess.hpp Range.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
