cmake_minimum_required (VERSION 3.15)

# Skip compiler tests...
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

# Generic build
set(CMAKE_SYSTEM_NAME Generic)

project(attiny85 C CXX ASM)

# Set our compiler (generic location)
# TODO: make OS agnostic
set(CMAKE_C_COMPILER "avr-gcc.exe")
set(CMAKE_CXX_COMPILER "avr-g++.exe")
set(CMAKE_ASM_COMPILER   "avr-gcc.exe")

set(GENERAL_FLAGS "-Wall -g -Og -mmcu=attiny85")
set(CMAKE_C_FLAGS "${GENERAL_FLAGS}")
set(CMAKE_CXX_FLAGS "${GENERAL_FLAGS}")

add_definitions(-DF_CPU=1000000)

# Our executable!
add_executable(main.elf 
                main.cpp)