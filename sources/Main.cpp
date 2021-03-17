#include "Core.hpp"

int main()
{
    int exitCode = 0;
    Core *core;

    core = new Core();
    core->init();
    printf("initiated\n");
    core->run();
    return (exitCode);
}