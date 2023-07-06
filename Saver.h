#pragma once

#include "Templates.h"

//-------------------------------------------------------------------------------------------------------------------------------
enum class ESave_Menu: unsigned char
{
	Handler,
	Save,
	Load,
	Add_Data,
	Delete,
	Exit
};
//-------------------------------------------------------------------------------------------------------------------------------
class AsSaver
{
public:
	~AsSaver();  // Save Data time when file delete
	AsSaver();

	void Init();

private:
	void Handler_Main_Menu();
	void Choser();  // Choose option or main menu
	void Add_Or_Erase_Data(bool is_erase);  // Add Data Beta
	void Save_To_File();  // Save
	void Read_Lines_From_File(const bool is_need_to_print = true);  // Load
	void Refactoring_String(const string &text, string &to_array, int &int_to_array);
	ESave_Menu Proccesing_Reguest();

	void Print_Out_Map(map<string, int> &anime_map);  // Show all Arrays in console
	void Check_If_File_Excist();  // if file doesn`t exsist creating it
	string Input_Handler(bool &is_paused, bool &is_end, int &anime_series);  // Handl input from console
	void Add_To_Specifer_Lists(bool &is_paused, bool &is_end, string &anime_title_to_array, int &anime_series);  // Add to arrays

	ESave_Menu Save_Menu;  // Saver Menu
	int Counter_List;
	double Max_Array_Size;

	ASlasher Slasher;  // Title for program

	map<string, int> Anime_Map;
	map<string, int> Anime_Map_End_Watch;
	map<string, int> Anime_Map_Paused;
	map<string, int>::iterator It_Anime_Map;
	map<string, int>::iterator It_Anime_Map_Pause;
	map<string, int>::iterator It_Anime_Map_End_Watch;

	static const string Warning;
	static const string End_Watch;
	static const string Pause_Anime;
	static const string Saver_Version;
	static const string Titles;
	static const char Space;
	static const char Left_Mark;
	static const char Right_Mark;
	static const string Seasons[];

};
//-------------------------------------------------------------------------------------------------------------------------------
