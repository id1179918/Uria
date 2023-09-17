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

#include <ncurses.h>
#include <iostream>

//void writeTextBufferWithMenu(WINDOW *, std::string, screenCoords_t);

class Graphics {
  public:

    void rectangle(int, int, int, int, WINDOW *);

    Graphics();
    ~Graphics();
  private:
};