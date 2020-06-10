#include "except.h"

const char* Except::what() const{
	static std::string msg = std::invalid_argument::what();
	msg = "\nWrong point: [";
	msg += std::to_string(wrongX);
	msg += ", ";
	msg += std::to_string(wrongY);
	msg += "]";
	

	return msg.data();
}