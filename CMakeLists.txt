cmake_minimum_required(VERSION 3.25)
project(irslinger C)
include_directories(".")
find_library(LIBPIGPIO pigpio REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
link_libraries(${LIBPIGPIO} m pthread)
add_executable(test test.c irslinger.h)
add_executable(testRC5 testRC5.c irslinger.h)
add_executable(testRawCodes testRawCodes.c irslinger.h)
