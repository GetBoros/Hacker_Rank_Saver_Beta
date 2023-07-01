#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------------
enum class EColor: unsigned char
{
	Red,
	Green,
	Orange
};
//------------------------------------------------------------------------------------------------------------------
enum class EFruit: unsigned char
{
	Apple,
	Orange,
	Pear
};
//------------------------------------------------------------------------------------------------------------------
template <typename T> struct Traits
{
};
//------------------------------------------------------------------------------------------------------------------
template<> class Traits<EColor>
{
public:
	static string Name(int index)
	{
		switch (static_cast<EColor>(index) )
		{
		case EColor::Red:
			return " Red";

		case EColor::Green:
			return " Green";

		case EColor::Orange:
			return " Orange";

		default:
			return " Unknown";
		}
	}
};
//------------------------------------------------------------------------------------------------------------------
template<> class Traits<EFruit>
{
public:
	static string Name(int index)
	{
		switch (static_cast<EFruit>(index) )
		{
		case EFruit::Apple:
			return " Apple";

		case EFruit::Orange:
			return " Orange";

		case EFruit::Pear:
			return " Pear";

		default:
			return " Unknown";
		}
	}
};
//------------------------------------------------------------------------------------------------------------------
