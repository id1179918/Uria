#ifndef INTERFACE_TOOL_HPP_
#define INTERFACE_TOOL_HPP_

#include "Core.hpp"
#include "Tool.hpp"

class Core;
class Tool;

class InterfaceTool {
    public:
        InterfaceTool();
        ~InterfaceTool();

        enum ScreenSetup {
            WIDE = 0,
            SPLITED_V = 1,
            SPLITED_H = 2,
            MENU = 3
        };

        int initTools();
        int handleInputs(Keys::Key);
        int update(Keys::Key);
        int render(WINDOW *);
        Tool *getSpecificTool(const char *);

    private:
        std::vector<int> _screenSetup;
        std::vector<Tool *> _tools;
        Tool *_currentTool;
        //Tool *_notepad;
        //Tool *_reminder;
        //Tool *_calendar;
        //Tool *_menu;
};

#endif