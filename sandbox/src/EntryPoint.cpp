
#include <CLI/CLI.hpp>
#include <Log.h>
#include <iostream>

#include "Sandbox.h"

int main(int argc, char* argv[])
{
    logging::Log LOGGER = logging::Log();

    std::string addToMessage = "It seems no console support has been activated!";
    CLI::App cli{"App description"};
    cli.add_option("Add to message",
                   addToMessage,
                   "String to append to message");
    CLI11_PARSE(cli, argc, argv);

    auto* sandbox = new Sandbox();
    std::cout << sandbox->message() << std::endl;
    std::cout << addToMessage << std::endl;
    sandbox->test();
    delete sandbox;
}