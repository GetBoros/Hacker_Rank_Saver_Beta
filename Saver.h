﻿#pragma once

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
	~AsSaver();
	AsSaver();

	void Init();

private:
	void Handler_Main_Menu();
	void Choser();  // Choose option or main menu
	void Add_Data_To_List_New_Beta();  // Add Data Beta
	void Delete_Data_From_List();  // Delete from array
	void Save_To_File();  // Save
	void Read_Lines_From_File();  // Load
	void Refactoring_String(const string &text, string &to_array, int &int_to_array);
	ESave_Menu Proccesing_Reguest();

	void Print_Out_Map(map<string, int> &anime_map);  // Show all Arrays in console
	void Check_If_File_Excist();  // if file doesn`t exsist creating it
	string Input_Handler(bool &is_paused, bool &is_end, int &anime_series);  // Handl input from console
	void Add_To_Specifer_Lists(bool &is_paused, bool &is_end, string &anime_title_to_array, int &anime_series);  // Add to arrays

	ESave_Menu Save_Menu;
	int Counter_List;
	double Max_Array_Size;

	ASlasher Slasher;
	AsSimple_Timer simple_timer;

	map<string, int> Anime_Map;
	map<string, int> Anime_Map_End_Watch;
	map<string, int> Anime_Map_Paused;
	map<string, int>::iterator It_Anime_Map;
	map<string, int>::iterator It_Anime_Map_Pause;

	static const string Warning;
	static const string End_Watch;
	static const string Pause_Anime;
	static const string Saver_Version;
	static const string Titles;
};
//-------------------------------------------------------------------------------------------------------------------------------
