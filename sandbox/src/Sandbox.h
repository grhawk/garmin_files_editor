#ifndef GARMIN_FILES_EDITOR_SANDBOX_H
#define GARMIN_FILES_EDITOR_SANDBOX_H

#include <garmin_files_editor.h>
#include <pugixml.hpp>
#include <iostream>
#include <vector>

class Sandbox
{
private:
    const char* p_message =
            garmin_files_editor::Application::dummyFunction();
    garmin_files_editor::Application app;
public:
    Sandbox()
            : app(garmin_files_editor::Application()) {}
    ~Sandbox() = default;
    const char* message();

    void test();
};


#endif //GARMIN_FILES_EDITOR_SANDBOX_H
