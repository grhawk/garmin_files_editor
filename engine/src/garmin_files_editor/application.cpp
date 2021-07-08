#include <iostream>
#include <Log.h>

#include "application.h"

namespace garmin_files_editor {

  Application::Application() 
  {
    _LOG_CRITICAL("Logging is included!");
    std::cout << "Starting application!" << std::endl;
  }

  const char* Application::dummyFunction()
  {
    return "Hello!";
  }

  Application::~Application() = default;
}
