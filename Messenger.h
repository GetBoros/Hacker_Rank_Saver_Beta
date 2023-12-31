#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------------
class AMsg
{
public:
	AMsg(string msg);

	virtual string Get_Msg();

private:
	string Msg;
};
//------------------------------------------------------------------------------------------------------------------
class ABrakets_Msg: public AMsg
{
public:
	ABrakets_Msg(string msg);

	virtual string Get_Msg();

private:

};
//------------------------------------------------------------------------------------------------------------------
class APrinter
{
public:
	APrinter();

	void Print(AMsg *msg);

private:

};
//------------------------------------------------------------------------------------------------------------------
