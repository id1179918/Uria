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
        void displayMenuNav(WINDOW *);

        Tool *changeMenuToolSelectionAbove(Tool *);
        Tool *changeMenuToolSelectionBelow(Tool *);

        Tool *getHighlightedTool(void);
        bool getToggle();
    private:
        Tool *_highlightTool;
        bool _toggle;

        std::vector<Tool *> _tools;
};

#endif