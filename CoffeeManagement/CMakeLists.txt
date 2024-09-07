cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CoffeeManagement)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    main.c
    utils/menu.c
    utils/order.c
    utils/admin.c
    utils/files.c
)

# Add the executable
add_executable(CoffeeManagement ${SOURCES})

# Add the header files
target_include_directories(CoffeeManagement PUBLIC
                           "${PROJECT_SOURCE_DIR}/include")