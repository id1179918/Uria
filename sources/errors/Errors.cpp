
#include "Errors.hpp"

Errors::Errors(std::ostream &stream, const std::string &msg) throw()
	: _ostream(stream), _output(msg) {}

Errors::~Errors(void) throw() {}

const char *Errors::msg(void) const throw()
{
	return _output.c_str();
}