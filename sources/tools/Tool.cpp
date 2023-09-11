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
    this->myfile.open("test.txt");
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

std::vector<int> Tool::getCursor(void)
{
    return (this->_cursor);
}

void Tool::setCursor(std::vector<int> cursor)
{
    this->_cursor = cursor;
    return;
}

void Tool::setCursorChar(char c)
{
  this->_cursorChar = c;
}

const char *Tool::getCursorChar(void)
{
  switch (this->_cursorChar) {
    case 'a':
        return ("a");
    case 'b':
        return ("b");
    case 'c':
        return ("c");
    case 'd':
        return ("d");
    case 'e':
        return ("e");
    case 'f':
        return ("f");
    case 'g':
        return ("g");
    case 'h':
        return ("h");
    case 'i':
        return ("i");
    case 'j':
        return ("j");
    case 'k':
        return ("k");
    case 'l':
        return ("l");
    case 'm':
        return ("m");
    case 'n':
        return ("n");
    case 'o':
        return ("o");
    case 'p':
        return ("p");
    case 'q':
        return ("q");
    case 'r':
        return ("r");
    case 's':
        return ("s");
    case 't':
        return ("t");
    case 'u':
        return ("u");
    case 'v':
        return ("v");
    case 'w':
        return ("w");
    case 'x':
        return ("x");
    case 'y':
        return ("y");
    case 'z':
        return ("z");
    case ' ':
        return (" ");
    break;
  }
  return "\0";
}

std::vector<int> Tool::findCursorNextPosition()
{
  return {50, 50};
};