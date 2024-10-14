cmake_minimum_required(VERSION 3.18.0...${CMAKE_VERSION})
project(LoadSimmetrixModel)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
# Find the Simmetrix package (adjust the path to your Simmetrix installation)
find_package(SimModSuite MODULE REQUIRED)
include_directories(${SIMMODSUITE_INCLUDE_DIR})
add_executable(main main.cpp)
target_link_libraries(main ${SIMMODSUITE_LIBS})
