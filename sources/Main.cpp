#include "Core.hpp"

int main()
{
    int exitCode = 0;
    Core *core;

    core = new Core();
    core->init();
    exitCode = core->run();
    return (exitCode);
}