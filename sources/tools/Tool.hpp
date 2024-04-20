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
#include <optional>


#include "Core.hpp"
#include "Coords.hpp"

//typedef struct tool_text_buffer {
//  std::string buffer;
//} tool_text_buffer_t;

class Tool {

    enum ToolPos {
        TOP,
        BOT
    };

    public:
        Tool(const char *);
        Tool(const char *, screenCoords_t);
        ~Tool();
        bool getToggle(void);
        void setToggle(bool);
        bool getIsUse(void);
        void setIsUse(bool);
        const char *getName();

        std::vector<int> getCursor(void);
        void setCursor(std::vector<int>);

        void moveCursorUp(void);
        void moveCursorDown(void);
        void moveCursorLeft(void);
        void moveCursorRight(void);

        const char *getCursorChar(void);
        void setCursorChar(char);

        std::string getBuffer(void);
        void setBuffer(std::string);
        void appendBuffer(char);
        void popBuffer();

        std::vector<int> findCursorNextPosition();
        std::vector<int> getCursorCurrentPosition();

        void setTime(std::time_t);
        std::time_t getTime();

        void displayToolWideWithMenu(WINDOW *);
        //void displayToolWideWithoutMenu(WINDOW *);

    private:
        std::ofstream myfile;
        std::vector<int> _cursor;
        char _cursorChar;
        const char *_name;
        bool _inUse;
        bool _toggle;
        Tool::ToolPos _posType;
        std::string _buffer;
};

#endif