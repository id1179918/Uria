#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <iostream>

class Errors: public std::exception {
public:
	Errors(std::ostream &, const std::string &) throw();
	~Errors(void) throw();
	const char *msg(void) const throw();

private:
	std::string _output;
	std::ostream &_ostream;
};

#endif
