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

    this->myfile.open("test.txt");

    this->_tools.push_back(notepad);
    this->_tools.push_back(reminder);
    this->_tools.push_back(calendar);
    this->_screenSetup = InterfaceTool::ScreenSetup::NONE;
    this->_keyboardMode = InterfaceTool::KeyboardScope::NAVIGATION;
    this->_menu = new Menu(this->_tools);
    this->_currentTool = nullptr;
}

InterfaceTool::~InterfaceTool()
{
    for (auto it = this->_tools.begin(); it != this->_tools.end(); it++) {
        Tool *tmp = *it;
        delete tmp;
    }
    this->myfile.close();
}

void InterfaceTool::setKBMode(void)
{
    switch (this->_keyboardMode) {
        case InterfaceTool::KeyboardScope::TYPING:
            this->_keyboardMode = InterfaceTool::KeyboardScope::NAVIGATION;
            break;
        case InterfaceTool::KeyboardScope::NAVIGATION:
            this->_keyboardMode = InterfaceTool::KeyboardScope::TYPING;
            break;
    }
    return;
}

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

int InterfaceTool::handleInputsTyping(Keys::Key event)
{
    switch ((int) event) {
        //case (event < 26):
        //    return (1);
    }
    return (0);
}

int InterfaceTool::handleInputsNav(Keys::Key event)
{
    if (this->_menu->getToggle() == true && this->_currentTool == nullptr) {
        switch ((int) event) {
            case Keys::Key::K_UP:
                this->_menu->changeMenuToolSelectionAbove(this->_menu->getHighlightedTool());
                break;
            case Keys::Key::K_DOWN:
                this->_menu->changeMenuToolSelectionBelow(this->_menu->getHighlightedTool());
                break;
        }
    }
    return (0);
}

int InterfaceTool::update(Keys::Key event)
{
    switch ((int) event) {
        case Keys::K_CONTROL:
            this->setKBMode();
            break;
        default:
            if (this->_keyboardMode == InterfaceTool::KeyboardScope::NAVIGATION) {
                this->handleInputsNav(event);
            } else if (this->_keyboardMode == InterfaceTool::KeyboardScope::TYPING) {
                this->handleInputsTyping(event);
            }
            break;
    }
    return (0);
}

int InterfaceTool::render(WINDOW *_window)
{
    //Global rectangle frame
    rectangle(0, 0, (COLS - 1), (LINES - 1), _window);
    //Menu config
    //Tool *notepad_tool = this->getSpecificTool("NOTEPAD");
    //Tool *reminder_tool = this->getSpecificTool("REMINDER");
    //Tool *calendar_tool = this->getSpecificTool("CALENDAR");
    if (this->_menu != nullptr) {
        if (_keyboardMode == InterfaceTool::KeyboardScope::TYPING) {
            if (this->_menu->getToggle() == true && this->_currentTool == nullptr) {
                this->_menu->displayMenuTyping(_window);
                //switch ((int) this->_screenSetup) {}
            }
        } else if (_keyboardMode == InterfaceTool::KeyboardScope::NAVIGATION) {
            if (this->_menu->getToggle() == true && this->_currentTool == nullptr) {
                this->_menu->displayMenuNav(_window);
                //switch ((int) this->_screenSetup) {}
            }
        }
    }
    wrefresh(_window);
    return (0);
}