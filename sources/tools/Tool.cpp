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

const char *Tool::getName()
{
    return (this->_name);
}