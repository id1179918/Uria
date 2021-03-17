#include "InterfaceTool.hpp"
#include "Tool.hpp"
#include "Core.hpp"
#include "Ncurses.hpp"
#include "Menu.hpp"


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
    this->_screenSetup = InterfaceTool::ScreenSetup::NONE;
    this->_currentTool = menu;
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
        //    return (1);
        case Keys::K_CONTROL:
            return (2);
    }
    return (0);
}

int InterfaceTool::update(Keys::Key event)
{
    this->handleInputs(event);
    return (0);
}

int InterfaceTool::render(WINDOW *_window, Keys::Scope _scope)
{
    //Global rectangle frame
    rectangle(0, 0, (COLS - 1), (LINES - 1), _window);
    //Menu config
    Tool *menu_tool = this->getSpecificTool("MENU");
    //Tool *notepad_tool = this->getSpecificTool("NOTEPAD");
    //Tool *reminder_tool = this->getSpecificTool("REMINDER");
    //Tool *calendar_tool = this->getSpecificTool("CALENDAR");
    if (menu_tool != nullptr) {
        if (_scope == Keys::Scope::TYPING) {
            if (menu_tool->getToggle() == true) {
                displayMenuTyping(_window);
                //switch ((int) this->_screenSetup) {}
            }
        } else if (_scope == Keys::Scope::NAVIGATION) {
            if (menu_tool->getToggle() == true) {
                if (std::strcmp(this->_currentTool->getName(), "MENU") == 0)
                    displayMenuNav(_window);
                //switch ((int) this->_screenSetup) {}
            }
        }
    }
    //for (auto it = this->_tools.begin(); it != this->_tools.end(); it++) {
    //    Tool *tmp = *it;
    //}
    wrefresh(_window);
    return (0);
}