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
#include <vector>

#include "Core.hpp"

class Tool {

    typedef struct bounds {
      int x;
      int y;
    }bounds_t;

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

        std::vector<int> getCursor(void);
        void setCursor(std::vector<int>);
        
        std::vector<bounds_t> getBounds(void);
        void setBounds(std::vector<bounds_t>);

        void setTime(std::time_t);
        std::time_t getTime();

        void displayToolWideWithMenu(WINDOW *);
        //void displayToolWideWithoutMenu(WINDOW *);

    private:
        std::vector<int> _cursors;
        std::vector<bounds_t> _bounds;
        const char *_name;
        bool _inUse;
        bool _toggle;
        Tool::ToolPos _posType;
};

#endif