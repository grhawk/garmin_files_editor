#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

#include<gtest/gtest.h>

#include<garmin_files_editor.h>

TEST(Example, ExampleTest){
ASSERT_STREQ(garmin_files_editor::Application::dummyFunction(), "Hello!");
}

#pragma clang diagnostic pop