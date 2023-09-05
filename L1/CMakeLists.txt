cmake_minimum_required(VERSION 3.0.0)
project(main)

add_executable(main main.cpp)

add_subdirectory(lib)

target_include_directories(${PROJECT_NAME} PRIVATE lib)
target_link_directories(${PROJECT_NAME} PRIVATE lib)

target_link_libraries(${PROJECT_NAME} Lib)


