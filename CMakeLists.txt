cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJECT garmin_files_editor)

project(${PROJECT} VERSION 0.1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

find_package(Boost REQUIRED COMPONENTS date_time)

include(cmake/gtest.cmake)

add_subdirectory(engine)
add_subdirectory(sandbox)
add_subdirectory(libs/CLI11 EXCLUDE_FROM_ALL)
add_subdirectory(libs/pugixml EXCLUDE_FROM_ALL)
add_subdirectory(libs/spdlog EXCLUDE_FROM_ALL)
add_subdirectory(logging EXCLUDE_FROM_ALL)

