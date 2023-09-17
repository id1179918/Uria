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

#include "Tool.hpp"
#include "Menu.hpp"
#include "FileManager.hpp"
#include "Ncurses.hpp"

#include <vector>

typedef struct screenCoords {
  int size_x;
  int size_y;
  int menu_origin_x;
  int menu_origin_y;
  int menu_end_x;
  int menu_end_y;
  int tool_origin_x_menu_active, tool_origin_y_menu_active, tool_end_x_menu_active, tool_end_y_menu_active;
  int tool_origin_x_menu_unactive, tool_origin_y_menu_unactive, tool_end_x_menu_unactive, tool_end_y_menu_unactive;
} screenCoords_t;

class InterfaceTool {
    public:
        InterfaceTool();
        InterfaceTool(WINDOW *);
        InterfaceTool(WINDOW *, int, int);
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
        int initCoods();

        int handleInputsTyping(Keys::Key);
        int handleInputsNav(Keys::Key);

        int update(Keys::Key);
        int render(WINDOW *);

        void setKBMode(void);

        Tool *getSpecificTool(const char *);
        int getCurrentToolIndex(void);

        void changeCurrentToolLeft(void);
        void changeCurrentToolRight(void);

        void toogleOffAllTools(void);

        FileManager *fileManager(void);

        // displaying

        // functions responsible for displaying the tools, given the menu is toggled or not
        void displayToolsWithMenuNav(WINDOW *);
        void displayToolsWithMenuTyp(WINDOW *);
        void displayToolsWithoutMenuNav(WINDOW *);
        void displayToolsWithoutMenuTyp(WINDOW *);

        void displayMenuTyping(WINDOW *);
        void displayMenuNavSelected(WINDOW *);
        void displayMenu(WINDOW *);

        // dev
          std::ofstream myfile;
          //Use to debug directly on terminal window
          WINDOW *_window;

          const char *screenSetupToString() {
            switch (this->_screenSetup)
            {
            case ScreenSetup::WIDE:
              return "WIDE";
              break;
            case ScreenSetup::SPLITED_V:
              return "SPLITED_V";
              break;
            case ScreenSetup::SPLITED_H:
              return "SPLITED_H";
              break;
            case ScreenSetup::SPLITED_VH:
              return "SPLITED_VH";
              break;
            case ScreenSetup::NONE:
              return "NONE";
              break;
            }
            return "NONE";
          }

    private:

        Graphics *_engine;

        InterfaceTool::ScreenSetup _screenSetup;

        InterfaceTool::KeyboardScope _keyboardMode;

        std::vector<Tool *> _tools;

        FileManager *_fileManager;

        screenCoords_t _coords;

        Menu *_menu;
        Tool *_currentTool;

        int _x, _y;
};

#endif