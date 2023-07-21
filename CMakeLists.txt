cmake_minimum_required(VERSION 3.25)
project(STCTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(STCTest main.cpp Ffile.h Statistic.h VisualFunctions.h ConfigBarChart.h Histogram.h)

find_package(OpenGL REQUIRED)

target_include_directories(STCTest PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(STCTest PUBLIC ${OPENGL_LIBRARIES})

find_package(GLUT REQUIRED)

target_include_directories(STCTest PUBLIC ${GLUT_INCLUDE_DIR})
target_link_libraries(STCTest PUBLIC ${GLUT_LIBRARIES})
