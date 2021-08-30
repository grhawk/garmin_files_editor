
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/engine/src)
include_directories(${PROJECT_SOURCE_DIR}/tests/helpers)


add_executable(${PROJECT_NAME}-test test1.cpp
        garmin_files_editor/tcx/models/PositionTest.cpp
        garmin_files_editor/tcx/models/TrackpointTest.cpp
        helpers/test_helper_functions.h
        helpers/test_helper_functions.cpp)
target_link_libraries(${PROJECT_NAME}-test gtest_main ${PROJECT_NAME})

gtest_discover_tests(${PROJECT_NAME}-test)