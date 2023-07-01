#include "Config.h"

// AsConfig
const char AsConfig::Player_Query[] = "Enter Task Number What you want to see: 2 - 10 or 11 exit\nTask: ";
const string AsConfig::Words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const string AsConfig::Path = "MyFile.txt";
//------------------------------------------------------------------------------------------------------------------
void AsConfig::Throw()
{
	throw 13;
}
//------------------------------------------------------------------------------------------------------------------
void AsConfig::Text_Print_To_Console(string text_to_console, bool slash, string second_text)
{
    if (slash)
        cout << AsTools::Slash_String << endl;

    cout << text_to_console + second_text;
}
//------------------------------------------------------------------------------------------------------------------
void AsConfig::Print_Player_Query()
{
    cout << Player_Query;
}
//------------------------------------------------------------------------------------------------------------------

