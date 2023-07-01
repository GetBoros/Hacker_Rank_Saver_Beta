#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------------
class AFunctor_Example
{
public:
	AFunctor_Example();

	void operator ()()
	{// operator() overwrited
		cout << "My Functor " << Count << endl; Count++;
	};
	void operator ()(int value)
	{// operator(int value) overwrited
		if (value % 2 == 0)
		{
			Even_Sum = Even_Sum + value;
			Even_Count++;
		}
	};
	int operator ()(int a, int b)
	{// operator(int a, int b) overwrited
		cout << "My Functor " << Count << endl; Count++; return a + b;
	};

	void Show_Event_Sum();
	void Show_Event_Count();

private:
	int Count;
	int Even_Sum;
	int Even_Count;
};
//------------------------------------------------------------------------------------------------------------------
