#pragma once

#include <iostream>
#include <limits>
#include <Windows.h>
#include <sstream>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>
#include <stack>
#include <fstream>
#include <functional>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <utility> 
#include <Windows.h>
#include <string>
#include <locale>
#include <iomanip>
#include <cassert>

//------------------------------------------------------------------------------------------------------------------
class AsSimple_Timer
{
public:
	~AsSimple_Timer();
	AsSimple_Timer();

private:
	std::chrono::steady_clock::time_point start, end;
	std::chrono::duration<float> duration;
};
//------------------------------------------------------------------------------------------------------------------
class ASlasher
{
public:
	~ASlasher();
	ASlasher(const std::string &text_to_print);

private:
	std::string Text_To_Print;
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
