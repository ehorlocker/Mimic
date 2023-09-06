# Mimic
cmake_minimum_required(VERSION 3.25)
project(Mimic VERSION 0.01 DESCRIPTION "Mimic Game Engine")

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB SOURCES src/**.cpp)
add_library(${PROJECT_NAME} "${SOURCES}")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		spdlog
	PRIVATE
		
)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC
		spdlog
	PRIVATE
		
)