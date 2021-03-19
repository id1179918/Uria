#include "Core.hpp"
#include "Ncurses.hpp"
#include "InterfaceTool.hpp"
#include "Menu.hpp"

Menu::Menu(std::vector<Tool *> tools)
{
    this->_tools = tools;
    this->_highlightTool = tools.front();
    this->_toggle = true;
}

Menu::~Menu()
{}

bool Menu::getToggle()
{
    return (this->_toggle);
}

Tool *Menu::getHighlightedTool(void)
{
    return (this->_highlightTool);
}

void Menu::changeMenuToolSelectionAbove(Tool *tool) {
    try {
        for (std::vector<Tool *>::iterator it = this->_tools.begin(); it != this->_tools.end(); it++) {
            Tool *readingTool = *it;
            if (std::strcmp(readingTool->getName(), tool->getName()) == 0) {
                if (it == this->_tools.begin())
                    this->_highlightTool = this->_tools.back();
                else
                    this->_highlightTool = readingTool;
                return;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Uria error from Menu module: " << e.what() << std::endl;
    }
    return;
}

void Menu::changeMenuToolSelectionBelow(Tool *tool)
{
    try {
        for (std::vector<Tool *>::iterator it = this->_tools.begin(); it != this->_tools.end(); it++) {
            Tool *readingTool = *it;
            if (std::strcmp(readingTool->getName(), tool->getName()) == 0) {
                if (it++ == this->_tools.end())
                    this->_highlightTool = this->_tools.front();
                else
                    this->_highlightTool = readingTool;
                return;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Uria error from Menu module: " << e.what() << std::endl;
    }
    return;
}

void Menu::displayMenuTyping(WINDOW *_window)
{
    rectangle(1, 1, (COLS - COLS + 14), (LINES - 2), _window);
    wattron(_window, COLOR_PAIR(2));
    mvwprintw(_window, (LINES - LINES) + 2, (COLS - COLS) + 6, "MENU");
    wattroff(_window, COLOR_PAIR(2));
    mvwprintw(_window, (LINES - LINES) + 6, (COLS - COLS) + 5, "NOTEPAD");
    mvwprintw(_window, (LINES - LINES) + 8, (COLS - COLS) + 4, "REMINDER");
    mvwprintw(_window, (LINES - LINES) + 10, (COLS - COLS) + 4, "CALENDAR");
    return;
}

void Menu::displayMenuNav(WINDOW *_window)
{
    int verticalOffset = 6;

    wattron(_window, COLOR_PAIR(3));
    rectangle(1, 1, (COLS - COLS + 14), (LINES - 2), _window);
    wattroff(_window, COLOR_PAIR(3));
    wattron(_window, COLOR_PAIR(2));
    mvwprintw(_window, (LINES - LINES) + 2, (COLS - COLS) + 6, "MENU");
    wattroff(_window, COLOR_PAIR(2));
    for (std::vector<Tool *>::iterator it = this->_tools.begin(); it != this->_tools.end(); it++) {
            Tool *readingTool = *it;
            if (std::strcmp(readingTool->getName(), this->_highlightTool->getName()) == 0) {
                wattron(_window, COLOR_PAIR(15));
                mvwprintw(_window, (LINES - LINES) + verticalOffset, (COLS - COLS) + 4, this->_highlightTool->getName());
                wattroff(_window, COLOR_PAIR(15));
            } else {
                mvwprintw(_window, (LINES - LINES) + verticalOffset, (COLS - COLS) + 4, readingTool->getName());
            }
            verticalOffset += 2;
    }
    return;
}