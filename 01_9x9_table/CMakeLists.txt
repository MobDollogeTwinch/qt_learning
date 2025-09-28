cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# ------------
project(01_9x9_table)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
file(GLOB sources *.cpp)
add_executable(01_9x9_table ${sources})
target_link_libraries(01_9x9_table PRIVATE Qt6::Widgets)

# ------------
set_target_properties(01_9x9_table PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)