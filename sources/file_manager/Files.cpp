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

#include "Files.hpp"

//Files::Files(){}

Files::Files(std::string name)
{
  this->_name = name;
}

Files::Files(std::string name, std::string content)
{
  this->_name = name;
  this->_content = content;
}

Files::~Files()
{
}

bool Files::isCached(void)
{
  if (!this->_content.empty())
    return true;
  else
    return false;
}

std::string Files::getContent(void)
{
  if (!this->_content.empty())
    return this->_content;
  else
    return std::string();
}

void Files::setContent(std::string content)
{
  this->_content = content;
}
