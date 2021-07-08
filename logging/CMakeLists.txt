set(PROJECT Logging)

project(${PROJECT} VERSION 0.1.0)

add_library(${PROJECT_NAME} Log.cpp Log.h)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})