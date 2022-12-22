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
    int exitCode = 0;
    Core *core;

    core = new Core();
    exitCode = core->init();
    if (exitCode != 0)
      exit(84);
    else {
      core->run();
    }

    return (exitCode);
}