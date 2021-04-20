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

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Core.hpp"
#include "Ncurses.hpp"
#include "InterfaceTool.hpp"
#include "Tool.hpp"

class Menu {
    public:
        Menu(std::vector<Tool *>);
        ~Menu();

        void displayMenuTyping(WINDOW *);
        void displayMenuNavSelected(WINDOW *);
        void displayMenu(WINDOW *);

        void changeMenuToolSelectionAbove(Tool *);
        void changeMenuToolSelectionBelow(Tool *);

        Tool *getHighlightedTool(void);
        bool getToggle(void);
        void setToogle(void);
    private:
        Tool *_highlightTool;
        bool _toggle;

        std::vector<Tool *> _tools;
};

#endif