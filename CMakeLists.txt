cmake_minimum_required(VERSION 3.16)

project(weyes LANGUAGES C)

# Find raylib package
find_package(raylib REQUIRED)

add_executable(weyes main.c main.h)

# Link raylib and libm to your executable
target_link_libraries(weyes PRIVATE raylib m)

# Include raylib headers
target_include_directories(weyes PRIVATE ${raylib_INCLUDE_DIRS})

include(GNUInstallDirs)
install(TARGETS weyes
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
