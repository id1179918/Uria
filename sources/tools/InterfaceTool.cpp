#include "InterfaceTool.hpp"
#include "Tool.hpp"
#include "Core.hpp"


InterfaceTool::InterfaceTool()
{
    this->_toogleMenu = true;
}

InterfaceTool::~InterfaceTool()
{}

int InterfaceTool::handleInputs(Keys::Key event)
{
    switch (event) {
        case Keys::K_EXIT:
            return (1);
            break;
        //case (event < 26):
        //    return (1);a
    }
    return (0);
}

int InterfaceTool::update(Keys::Key event)
{
    this->handleInputs(event);
    return (0);
}

int InterfaceTool::render(WINDOW *_window)
{
    box(_window, ACS_VLINE, ACS_HLINE);
    if (this->_toogleMenu)
        attron(2);
        mvprintw((LINES - LINES) + 1, (COLS - COLS) + 5, "MENU");
        attroff(2);
    wrefresh(_window);
    return (0);
}