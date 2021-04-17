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

#ifndef INTERFACE_TOOL_HPP_
#define INTERFACE_TOOL_HPP_

#include "Core.hpp"
#include "Tool.hpp"
#include "Menu.hpp"

#include <vector>

class InterfaceTool {
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

        enum AvailableToolsMenu {
            NOTEPAD,
            REMINDER,
            CALENDAR
        };

        enum KeyboardScope {
            TYPING,
            NAVIGATION
        };

        int initTools();

        int handleInputsTyping(Keys::Key);
        int handleInputsNav(Keys::Key);

        int update(Keys::Key);
        int render(WINDOW *);

        void setKBMode(void);

        Tool *getSpecificTool(const char *);

        void changeCurrentToolLeft(void);
        void changeCurrentToolRight(void);

        // displaying

        // functions responsible for displaying the tools, given the menu is toggled or not
        void displayToolsWithMenuNav(WINDOW *);
        void displayToolsWithMenuTyp(WINDOW *);

        // dev
        std::ofstream myfile;

    private:
        InterfaceTool::ScreenSetup _screenSetup;

        InterfaceTool::KeyboardScope _keyboardMode;

        std::vector<Tool *> _tools;

        Menu *_menu;
        Tool *_currentTool;
};

#endif