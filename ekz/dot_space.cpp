#include "dot_space.h"

void Dot_space::print() const {
	cout << "[" << x << ", " << y << ", " << z << "]" << endl;
}

void Dot_space_not_virtual::print() const {
	cout << "[" << x << ", " << y << ", " << z << "]" << endl;
}