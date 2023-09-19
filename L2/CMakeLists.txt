cmake_minimum_required(VERSION 3.0.0)

# Enable optimization flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

# Enable gprof profiling
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")

project(main)

# find_package(Python3 REQUIRED COMPONENTS Interpreter Development NumPy)
# include_directories(${Python3_INCLUDE_DIRS})
add_executable(main main.cpp)

add_subdirectory(lib)

target_include_directories(${PROJECT_NAME} PRIVATE lib)
target_link_directories(${PROJECT_NAME} PRIVATE lib)

target_link_libraries(${PROJECT_NAME} Lib) # ${Python3_LIBRARIES} ${GMP_LIBRARIES}
