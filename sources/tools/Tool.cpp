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

//std::optional<std::vector<int>> whenOrNull(std::vector<int> pos) {
//    if (pos.at(0) > 0 && pos.at(1) > 0) {
//        return pos;
//    } else {
//        return NULL;
//    }
//}

Tool::Tool(const char *name)
{
    this->_name = name;
    this->_toggle = false;
    this->myfile.open("test.txt");
}

Tool::Tool(const char *name, screenCoords_t _coords)
{
    this->_name = name;
    this->_toggle = false;
    this->myfile.open("test.txt");
    this->_cursor = {_coords.tool_end_x_menu_active + 1, _coords.tool_end_y_menu_active + 1};
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


void Tool::moveCursorUp(void)
{
    int x = this->_cursor[0];
    int y = this->_cursor[1] - 1;
    std::vector<int> newPos {x, y};
    this->setCursor(newPos);
    return;
};
void Tool::moveCursorDown(void)
{
    return;
};
void Tool::moveCursorLeft(void)
{
    return;
};
void Tool::moveCursorRight(void)
{
    return;
};

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
  return {25, 25};
};

std::vector<int> Tool::getCursorCurrentPosition()
{
    return (this->_cursor);
};

std::string Tool::getBuffer(void)
{
    return this->_buffer;
}

void Tool::setBuffer(std::string buffer)
{
    this->_buffer = buffer;
    return;
}

void Tool::appendBuffer(char c)
{
    this->_buffer.append(1, c);
    return;
}

void Tool::popBuffer()
{
    this->_buffer.pop_back();
    return;
}