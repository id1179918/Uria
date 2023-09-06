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
#ifndef CRYPT_HPP_
#define CRYPT_HPP_

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
#include <vector>
#include <iterator>

class Crypting {
    public:

      Crypting();
      ~Crypting();

      //TODO
        std::string encode(std::string);
        std::string decode(std::string);
};

#endif