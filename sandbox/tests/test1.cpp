#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#include<gtest/gtest.h>

#include <Log.h>
#include<Sandbox.h>

logging::Log LOGGER = logging::Log();

TEST(Example, ExampleTest){
Sandbox sandbox = Sandbox();
ASSERT_STREQ(sandbox.message(), "Hello!");
}

#pragma clang diagnostic pop
