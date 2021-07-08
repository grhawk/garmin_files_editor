
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/engine/src)


add_executable(${PROJECT_NAME}-test test1.cpp)
target_link_libraries(${PROJECT_NAME}-test gtest_main ${PROJECT_NAME})

gtest_discover_tests(${PROJECT_NAME}-test)