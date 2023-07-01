#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------------
class AsComplex
{
public:
	int A, B;

	void Input(string str);

	friend AsComplex operator+(const AsComplex& complex_A, const AsComplex& complex_B);
	friend ostream &operator<<(ostream &out_string, const AsComplex &complex);
};
//------------------------------------------------------------------------------------------------------------------
