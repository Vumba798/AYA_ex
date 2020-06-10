#pragma once

#include <iostream>
#include <exception>
#include <string>

class Except : public std::invalid_argument{
private:
	float wrongX;
	float wrongY;
public:
	Except(std::string msg, float x, float y) 
	: std::invalid_argument(msg), wrongX(x), wrongY(y) {};
	const char* what() const override;
};