cmake_minimum_required(VERSION 3.12)
project(raytracing)

set(CMAKE_CXX_STANDARD 11)

# Add the pugixml library
add_subdirectory(pugixml)

# Define the source files for each executable
set(T1_SOURCES T1.cpp)
set(T2_SOURCES T2.cpp)
set(T3_SOURCES T3.cpp)
set(T4_SOURCES T4.cpp)
set(T5_SOURCES T5.cpp)

# Build each executable separately
add_executable(T1 ${T1_SOURCES})
add_executable(T2 ${T2_SOURCES})
add_executable(T3 ${T3_SOURCES})
add_executable(T4 ${T4_SOURCES})
add_executable(T5 ${T5_SOURCES})

# Link the pugixml library to each executable
target_link_libraries(T1 pugixml)
target_link_libraries(T2 pugixml)
target_link_libraries(T3 pugixml)
target_link_libraries(T4 pugixml)
target_link_libraries(T5 pugixml)
