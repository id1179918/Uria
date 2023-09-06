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

#include "Errors.hpp"

Errors::Errors(std::ostream &stream, const std::string &msg) throw() {
  this->_ostream = stream;
  this->_output = msg;
}

Errors::~Errors(void) throw() {}

const char *Errors::msg(void) const throw()
{
	return _output.c_str();
}