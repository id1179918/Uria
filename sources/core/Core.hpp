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
#include "ExitStatus.hpp"
#include "Ncurses.hpp"
#include "EventHandler.hpp"

#define BUFFER_SIZE 100


class InterfaceTool;
class FileManager;

class Core {
    public:
    	Core();
    	~Core();

        // Initializations
        int init();

        int run();
        Keys::Key getInput();
        void setIsRunning(bool);

        InterfaceTool *getTools(void);

        void setKBMode(void);

    private:
        WINDOW *_window;

        Graphics *_graphics;

        EventHandler *_eventHandler;

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