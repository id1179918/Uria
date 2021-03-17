#ifndef INTERFACE_TOOL_HPP_
#define INTERFACE_TOOL_HPP_

#include "Core.hpp"
#include "Tool.hpp"

class Core;
class Tool;

class InterfaceTool : public Core {
    public:
        InterfaceTool();
        ~InterfaceTool();

        enum ScreenSetup {
            WIDE = 0,
            SPLITED_V = 1,
            SPLITED_H =  2,
            SPLITED_VH = 3,
            NONE = 4
        };

        int initTools();
        int handleInputs(Keys::Key);
        int update(Keys::Key);
        int render(WINDOW *, Keys::Scope);
        Tool *getSpecificTool(const char *);

    private:
        ScreenSetup _screenSetup;
        std::vector<Tool *> _tools;
        Tool *_currentTool;
        //Tool *_notepad;
        //Tool *_reminder;
        //Tool *_calendar;
        //Tool *_menu;
};

#endif