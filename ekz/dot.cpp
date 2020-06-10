#include "dot.h"



void Dot::print() const {
	cout << "[" << x << ", " << y << "]" << endl;
}

std::ostream& operator<<(std::ostream& out, Dot& dot) {
	out << "[" << dot.x << ", " << dot.y << "]" << endl;
	return out;
}

std::istream& operator>>(std::istream& in, Dot& dot) {
	cout << "Input x: ";
	in >> dot.x;
	cout << "Input y: ";
	in >> dot.y;
	if (dot.x < 0 || dot.y < 0) {
		throw Except("The coordinates must be non-negative!", dot.x, dot.y);
	}
	return in;
}

bool operator<(const Dot& lhs, const Dot& rhs) {

	float lhsDist = sqrtf(pow(lhs.get_x(), 2) + pow(lhs.get_y(), 2));
	float rhsDist = sqrtf(pow(rhs.get_x(), 2) + pow(rhs.get_y(), 2));

	if (lhsDist < rhsDist) {
		return true;
	}
	else {
		return false;
	}
}




//not virtual
void Dot_not_virtual::print() const {
	cout << "[" << x << ", " << y << "]" << endl;
}

std::ostream& operator<<(std::ostream& out, Dot_not_virtual& dot) {
	out << "[" << dot.x << ", " << dot.y << "]" << endl;
	return out;
}

std::istream& operator>>(std::istream& in, Dot_not_virtual& dot) {
	cout << "Input x: ";
	in >> dot.x;
	cout << "Input y: ";	
	in >> dot.y;
	if (dot.x < 0 || dot.y < 0) {
		throw Except("The coordinates must be non-negative!", dot.x, dot.y);
	}
	return in;
}