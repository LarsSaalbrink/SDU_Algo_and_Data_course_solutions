cmake_minimum_required(VERSION 3.0.0)
project(main)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development NumPy)
include_directories(${Python3_INCLUDE_DIRS})

add_executable(main main.cpp)

add_subdirectory(lib)

target_include_directories(${PROJECT_NAME} PRIVATE lib)
target_link_directories(${PROJECT_NAME} PRIVATE lib)

target_link_libraries(${PROJECT_NAME} ${Python3_LIBRARIES} Lib ${GMP_LIBRARIES})
