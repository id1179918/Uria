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

#include "InterfaceTool.hpp"
#include "Tool.hpp"
#include "Core.hpp"
#include "Ncurses.hpp"

Tool::Tool(const char *name)
{
    this->_name = name;
    this->_toggle = false;
}

Tool::~Tool()
{}

bool Tool::getToggle()
{
    return (this->_toggle);
}

void Tool::setToggle(bool b)
{
    this->_toggle = b;
    return;
}

const char *Tool::getName()
{
    return (this->_name);
}

bool Tool::getIsUse(void)
{
  return (this->_inUse);
}
void Tool::setIsUse(bool inUse)
{
    this->_inUse = inUse;
    return;
}