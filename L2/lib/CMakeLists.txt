project(Lib)

# Find the pkg-config package for GMP
find_package(PkgConfig REQUIRED)
pkg_check_modules(GMP REQUIRED gmp)

add_library(Lib Lib.cpp Stack.cpp)
target_link_libraries(Lib PRIVATE ${GMP_LIBRARIES})