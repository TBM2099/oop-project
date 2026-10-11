cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_COMPILER "C:/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")
set(CMAKE_MAKE_PROGRAM "C:/msys64/ucrt64/bin/mingw32-make.exe")

project(QtTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/msys64/ucrt64")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(QtTest
    main.cpp
    mainwindow.cpp
    mainwindow.h
    
    hatem_20253050_1_5_9_13.cpp
    Mohammed_20253081_4_8_12_16.cpp
    Alaa_20253072_2_6_10_14.cpp
    Mohammed_20253073_3_7_11_15.cpp
    Filters.h
    Image_Class.h
    stb_impl.cpp
)

target_link_libraries(QtTest PRIVATE Qt6::Widgets)