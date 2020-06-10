// ekz.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <cmath>
#include "except.h"

using std::cin;
using std::cout;
using std::endl;

class Dot {
protected:
	float x;
	float y;
public:
	inline Dot(float a, float b) : x(a), y(b) {
		if (a < 0 || b < 0) {
			throw Except("coordinates must be positive",a,b);
		}
	};
	virtual void print() const;
	virtual ~Dot() {};
	inline float get_x() const{
		return x;
	}
	inline float get_y() const{
		return y;
	}

	friend std::ostream& operator<<(std::ostream& out, Dot &dot);
	friend std::istream& operator>>(std::istream& in, Dot& dot);
};

class Dot_not_virtual {
protected:
	float x;
	float y;
public:
	inline Dot_not_virtual(float a, float b) : x(a), y(b) {
		if (a < 0 || b < 0) {
			throw Except("coordinates must be positive", a, b);
		}
	};
	virtual void print() const;

	friend std::ostream& operator<<(std::ostream& out, Dot_not_virtual& dot);
	friend std::istream& operator>>(std::istream& in, Dot_not_virtual& dot);
};

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
