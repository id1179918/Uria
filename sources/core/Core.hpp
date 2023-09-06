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
}

#include <ctime>
#include <algorithm>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>

#include "FileManager.hpp"
#include "Keys.hpp"

#define BUFFER_SIZE 100

class InterfaceTool;
class FileManager;

class Core {
    public:
    	Core();
    	~Core();

        // Initializations
        int init();
        void initTerminal();
        void initColor();

        int run();
        Keys::Key getInput();
        void setIsRunning(bool);

        // Window settings
        void setWindow(WINDOW *);
        WINDOW *getWindow();

        InterfaceTool *getTools(void);
        FileManager *fileManager(void);

        void setKBMode(void);

    private:
        WINDOW *_window;
        int _height, _width, _row, _col;
        bool _isRunning;

        InterfaceTool *_toolInterface;

        FileManager *_fileManager;

        int initPipeCommunicationHandler();
        fd_set _ioReadFd;
        struct timeval _timeout;
        int _pipes[2]; // Pipe file descriptors
        char _pipeBuffer[BUFFER_SIZE]; // Buffer for reading from pipe
        pid_t _io_pid;
};

#endif