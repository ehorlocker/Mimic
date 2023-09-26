# Mimic
# maybe split into cmakes for each section?
cmake_minimum_required(VERSION 3.25)
project(Mimic VERSION 0.01 DESCRIPTION "Mimic Game Engine")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/build/Sandbox)
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time") 

add_compile_definitions(MZ_PLATFORM_WINDOWS MZ_BUILD_DLL MZ_ENABLE_ASSERTS)

file(GLOB SOURCES **.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Platform/Windows/WindowWindows.cpp)
add_library(${PROJECT_NAME} SHARED "${SOURCES}")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Events>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Core>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Platform/Windows>
		spdlog
		glfw
	PRIVATE
		
)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC
		spdlog
		glfw
	PRIVATE
		
)

target_precompile_headers(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mzpch.h)

ADD_CUSTOM_COMMAND(TARGET Mimic POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       ${CMAKE_BINARY_DIR}/Mimic/Mimic.dll
                       ${CMAKE_BINARY_DIR}/Sandbox
                   COMMENT "Copying 'Mimic' library to '${CMAKE_BINARY_DIR}/Sandbox'")