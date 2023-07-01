#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------------
class AString
{
public:
	~AString();
	AString();
	AString(const char *str);

	bool operator ==(const AString &other);
	bool operator !=(const AString &other);
	char &operator [](int index);
	AString &operator =(const AString &other);
	AString operator +(const AString &other);

	void Add_To_Array(const char *str);
	void Print();
	int Length();

private:
	char *Str;
	int Array_Length;
};
//------------------------------------------------------------------------------------------------------------------




// String Tutorials
/*

// getline(cin, temp);  // get line from cin to &temp
string temp;
getline(cin, temp);
cout << temp;


*/