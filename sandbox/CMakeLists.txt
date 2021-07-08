set(PROJECT ${CPACK_PROJECT_NAME}-sandbox)

project(${PROJECT} VERSION 0.1.0)

add_subdirectory(tests)

include_directories(${CMAKE_SOURCE_DIR}/engine/src)
add_executable(${PROJECT_NAME} src/EntryPoint.cpp src/Sandbox.cpp src/Sandbox.h)
add_library(${PROJECT_NAME}-lib src/Sandbox.cpp src/Sandbox.h)

target_link_libraries(${PROJECT_NAME} ${CPACK_PROJECT_NAME}-engine CLI11::CLI11)
target_link_libraries(${PROJECT_NAME}-lib ${CPACK_PROJECT_NAME}-engine)