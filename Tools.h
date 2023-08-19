#pragma once

#include "PreCompileHeader.h"

//------------------------------------------------------------------------------------------------------------------
class AsSimple_Timer
{
public:
	~AsSimple_Timer();
	AsSimple_Timer();
	AsSimple_Timer(bool is_life_time);

	double Get_Duration();

private:
	bool Is_Life_Time;

	std::chrono::steady_clock::time_point Start, End;
	std::chrono::duration<float> Duration;
};
//------------------------------------------------------------------------------------------------------------------
class ASlasher
{
public:
	~ASlasher();
	ASlasher(const std::string &text_to_print);

	static SYSTEMTIME Local_Time;
private:
	std::string Text_To_Print;

	static int Slasher_Counter;
};
//------------------------------------------------------------------------------------------------------------------
class AsTools
{
public:

	static const std::string Slash_String;
	static const AsSimple_Timer simple_timer;

private:

};
//------------------------------------------------------------------------------------------------------------------
