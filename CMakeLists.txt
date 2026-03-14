cmake_minimum_required(VERSION 3.16)
project(QuranReader)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Network)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(QuranReader main.cpp mainwindow.cpp mainwindow.h)

target_link_libraries(QuranReader Qt5::Core Qt5::Widgets Qt5::Network)