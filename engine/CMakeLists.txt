
set(PROJECT ${CPACK_PROJECT_NAME}-engine)

project(${PROJECT} VERSION 0.1.0)

add_subdirectory(tests)

add_library(${PROJECT_NAME} src/garmin_files_editor.h src/garmin_files_editor/core.h src/garmin_files_editor/application.cpp src/garmin_files_editor/application.h)
target_link_libraries(${PROJECT_NAME} PUBLIC Logging) 