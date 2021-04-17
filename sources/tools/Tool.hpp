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

#ifndef TOOL_HPP_
#define TOOL_HPP_

#include <iostream>


#include "Core.hpp"

class Tool {

    enum ToolPos {
        TOP,
        BOT
    };

    public:
        Tool(const char *);
        ~Tool();
        bool getToggle(void);
        void setToggle(bool);
        bool getIsUse(void);
        void setIsUse(bool);
        const char *getName();

        void setTime(std::time_t);
        std::time_t getTime();

        void displayToolWideWithMenu(WINDOW *);
        //void displayToolWideWithoutMenu(WINDOW *);

    private:
        const char *_name;
        bool _inUse;
        bool _toggle;
        Tool::ToolPos _posType;
};

#endif