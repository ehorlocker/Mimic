# Mimic
cmake_minimum_required(VERSION 3.25)
project(glad VERSION 4.6 DESCRIPTION "glad OpenGL")

set(sources
	src/glad.c
)

#file(GLOB Sources "")
add_library(${PROJECT_NAME} STATIC
	${sources}
)

target_include_directories(${PROJECT_NAME} 
	PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/KHR>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/glad>
)
