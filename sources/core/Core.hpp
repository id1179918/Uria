#ifndef CORE_HPP_
#define CORE_HPP_

#include "Errors.hpp"

#include <algorithm>
#include <cstring>
#include <ctype.h>
#include <curses.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <term.h>
#include <vector>
#include <list>

class InterfaceTool;

namespace GConfig {
}

namespace Keys {
    enum Key {
        K_A,
        K_B,
        K_C,
        K_D,
    	K_E,
        K_F,
        K_G,
        K_H,
        K_I,
        K_J,
        K_K,
        K_L,
        K_M,
    	K_N,
    	K_O,
        K_P,
        K_Q,
        K_R,
    	K_S,
        K_T,
        K_U,
        K_V,
        K_W,
        K_X,
        K_Y,
        K_Z,
    	K_UP,
    	K_DOWN,
    	K_LEFT,
    	K_RIGHT,
    	K_SPACE,
        K_RETURN,
        K_BACKSPACE,
        K_EXIT,
    	K_UNDEFINED
    };
}

/*
Key operator<(Key &event)
{
    switch (key) {
        case 'a':
            return (K_A);
        case 'b':
            return (K_B);
        case 'c':
            return (K_C);
        case 'd':
            return (K_D);
        case 'e':
            return (K_E);
        case 'f':
            return (K_F);
        case 'g':
            return (K_G);
        case 'h':
            return (K_H);
        case 'i':
            return (K_I);
        case 'j':
            return (K_J);
        case 'k':
            return (K_K);
        case 'l':
            return (K_L);
        case 'm':
            return (K_M);
        case 'n':
            return (K_N);
        case 'o':
            return (K_O);
        case 'p':
            return (K_P);
        case 'q':
            return (K_Q);
        case 'r':
            return (K_R);
        case 's':
            return (K_S);
        case 't':
            return (K_T);
        case 'u':
            return (K_U);
        case 'v':
            return (K_V);
        case 'w':
            return (K_W);
        case 'x':
            return (K_X);
        case 'y':
            return (K_Y);
        case 'z':
            return (K_Z);
}
*/

class Core {
    public:
    	Core();
    	~Core();
        int init();
        void initTerminal();
        void initColor();
        int run();

        Keys::Key getInput();
        void setIsRunning(bool);

        void setWindow(WINDOW *);
        WINDOW *getWindow();

        InterfaceTool *getTools(void);
        // No setter because only need to be initialized
    private:
        WINDOW *_window;
        int _height, _width, _row, _col;

        bool _isRunning;
        InterfaceTool *_toolInterface;
};

#endif