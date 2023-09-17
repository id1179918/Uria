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

#include "Core.hpp"
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

bool Menu::getToggle(void)
{
    return (this->_toggle);
}

void Menu::setToogle(void)
{
    this->_toggle = !(this->_toggle);
    return;
}

Tool *Menu::getHighlightedTool(void)
{
    return (this->_highlightTool);
}

void Menu::changeMenuToolSelectionAbove(Tool *tool) {
    try {
        for (int it = 0; it != (int) this->_tools.size(); it++) {
            if (std::strcmp(this->_tools[it]->getName(), tool->getName()) == 0) {
                if (this->_tools[it] == this->_tools[0])
                    this->_highlightTool = this->_tools.back();
                else
                    this->_highlightTool = this->_tools[--it];
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
        for (int it = 0; it != (int) this->_tools.size(); it++) {
            if (std::strcmp(this->_tools[it]->getName(), tool->getName()) == 0) {
                if (this->_tools[it] == this->_tools[this->_tools.size() - 1])
                    this->_highlightTool = this->_tools.front();
                else
                    this->_highlightTool = this->_tools[++it];
                return;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Uria error from Menu module: " << e.what() << std::endl;
    }
    return;
}