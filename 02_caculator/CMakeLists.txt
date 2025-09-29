cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# ------------
project(02_caculator)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
file(GLOB sources *.cpp)
add_executable(02_caculator ${sources})
target_link_libraries(02_caculator PRIVATE Qt6::Widgets)

# ------------
set_target_properties(02_caculator PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)