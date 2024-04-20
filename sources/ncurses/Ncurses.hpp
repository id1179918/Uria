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
#include <stdlib.h>

#include "Coords.hpp"
#include "ExitStatus.hpp"

//void writeTextBufferWithMenu(WINDOW *, std::string, screenCoords_t);

class Graphics {
  public:
    int init();
    void initTerminal();
    void initColor();

    int getRow();
    int getCol();

    int render();

    void rectangle(int, int, int, int, WINDOW *);

    WINDOW *getWindow(void);
    void setWindow(WINDOW *);


    void printDebug(const char *);

    Graphics();
    ~Graphics();
  private:
    WINDOW *_window;
    int _height, _width, _row, _col;
};