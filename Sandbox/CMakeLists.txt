# Sandbox
cmake_minimum_required(VERSION 3.25)
project(Sandbox VERSION 0.01 DESCRIPTION "Sandbox for Mimic Game Engine")

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(MZ_PLATFORM_WINDOWS)

add_executable(${PROJECT_NAME} src/SandboxApp.cpp)

target_link_libraries(${PROJECT_NAME} Mimic)
target_include_directories(${PROJECT_NAME} PRIVATE Mimic)