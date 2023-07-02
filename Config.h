#pragma once

#include "Tools.h"

using namespace std;

class AsConfig
{
public:
	static void Throw();
	static void Text_Print_To_Console(string text_to_console, bool slash = true, string second_text = "");

	static void Print_Player_Query();

	static const int Max_Char_Symbol = 255;
	static const int Point_Array_Length = 5;
	static const int Thread_Sleep_For = 1000;
	static const string Words[];  // English words for numbers 1 to 9
	static const string Path;

private:
	static const char Player_Query[Max_Char_Symbol];

};
//------------------------------------------------------------------------------------------------------------------
