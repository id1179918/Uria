#include "InterfaceTool.hpp"
#include "Tool.hpp"
#include "Core.hpp"
#include "Ncurses.hpp"


InterfaceTool::InterfaceTool()
{
    Tool *notepad = new Tool("NOTEPAD");
    Tool *reminder = new Tool("REMINDER");
    Tool *calendar = new Tool("CALENDAR");
    Tool *menu = new Tool("MENU");

    this->_tools.push_back(notepad);
    this->_tools.push_back(reminder);
    this->_tools.push_back(calendar);
    this->_tools.push_back(menu);
    this->_screenSetup = {1, 0, 0, 0};
}

InterfaceTool::~InterfaceTool()
{}

Tool *InterfaceTool::getSpecificTool(const char *name)
{
    for (auto it = this->_tools.begin(); it != this->_tools.end(); it++) {
        Tool *tmp = *it;
        if (std::strcmp(tmp->getName(), name) == 0) {
            return (tmp);
        }
    }
    return (nullptr);
}

int InterfaceTool::initTools()
{
    return (0);
}

int InterfaceTool::handleInputs(Keys::Key event)
{
    switch ((int) event) {
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
    //Global rectangle frame
    rectangle(0, 0, (COLS - 1), (LINES - 1), _window);
    //Menu config
    Tool *menu_tool = this->getSpecificTool("MENU");
    if (menu_tool != nullptr) {
        if (menu_tool->getToggle() == true) {
            rectangle(1, 1, (COLS - COLS + 14), (LINES - 2), _window);
            wattron(_window, COLOR_PAIR(2));
            mvwprintw(_window, (LINES - LINES) + 2, (COLS - COLS) + 6, "MENU");
            wattroff(_window, COLOR_PAIR(2));
        }
        //switch ((int) ) {
        //    case:
        //}
    }
    //for (auto it = this->_tools.begin(); it != this->_tools.end(); it++) {
    //    Tool *tmp = *it;
    //}
    wrefresh(_window);
    return (0);
}