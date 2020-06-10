#pragma once

#include "dot.h"

class Dot_space : public Dot {
private:
	float z;
public:
	Dot_space(float a, float b, float c) : Dot(a, b), z(c) {};
	void print() const override final;
};

class Dot_space_not_virtual : public Dot_not_virtual {
private:
	float z;
public:
	Dot_space_not_virtual(float a, float b, float c) : Dot_not_virtual(a, b), z(c) {};
	void print() const override final;
};
