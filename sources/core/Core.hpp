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

#ifndef CORE_HPP_
#define CORE_HPP_

extern "C" {
    #include <time.h>
    #include <ctype.h>
    #include <curses.h>
    #include <ncurses.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <sys/ioctl.h>
    #include <unistd.h>
    #include <term.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <stdio.h>
}

#include <ctime>
#include <algorithm>
#include <cstring>
#include <string>
#include <exception>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>

#define BUFFER_SIZE 100

class InterfaceTool;

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
    	K_UNDEFINED,
        K_CONTROL,
        K_CLOSE
    };
};

class Core {
    public:
    	Core();
    	~Core();

        // Initializations
        int init();
        void initTerminal();
        void initColor();

        int run();
        int runClient();
        int runIOHandler();
        Keys::Key getEvent();

        Keys::Key getInput(int);
        void setIsRunning(bool);

        // Window settings
        void setWindow(WINDOW *);
        WINDOW *getWindow();

        InterfaceTool *getTools(void);

        void setKBMode(void);

    private:
        WINDOW *_window;
        int _height, _width, _row, _col;

        bool _isRunning;
        InterfaceTool *_toolInterface;

        int initPipeCommunicationHandler();
        fd_set _ioReadFd;
        struct timeval _timeout;
        int _pipes[2]; // Pipe file descriptors
        char _pipeBuffer[BUFFER_SIZE]; // Buffer for reading from pipe
        pid_t _io_pid;
};

#endif