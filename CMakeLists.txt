cmake_minimum_required(VERSION 3.29)
project(nes_emulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(nes_emulator main.cpp
        cpu/Bus.cpp
        cpu/Bus.h
        cpu/cpu.cpp
        cpu/cpu.h)
