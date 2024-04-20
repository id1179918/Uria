/*
-
  -
    -
  -
-
Uria - 2021

Thomas ROUSTAN
-
  -
    -
  -
-
*/

#include "Core.hpp"

int main()
{
    int exitCode;
    Core *core;

    core = new Core();
    exitCode = core->init();
    //printf("initiated\n");
    exitCode = core->run();
    return (exitCode);
}