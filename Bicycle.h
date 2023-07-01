#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------------
class IBicycle
{
public:
	IBicycle();

	virtual void Ewist_The_Wheel() = 0;
	virtual void Ride() = 0;

private:

};
//------------------------------------------------------------------------------------------------------------------
class ASimple_Bicycle : public IBicycle
{
public:
	ASimple_Bicycle();

	virtual void Ewist_The_Wheel();
	virtual void Ride();

private:

};
//------------------------------------------------------------------------------------------------------------------
class ASport_Bicycle : public IBicycle
{
public:
	ASport_Bicycle();

	virtual void Ewist_The_Wheel();
	virtual void Ride();

private:

};
//------------------------------------------------------------------------------------------------------------------
class AMan
{
public:
	AMan();

	void Ride_On(IBicycle &bicycle);
private:

};
//------------------------------------------------------------------------------------------------------------------
