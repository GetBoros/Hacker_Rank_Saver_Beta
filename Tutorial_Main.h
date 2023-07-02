#pragma once

#include "String.h"
#include "Action.h"
#include "Example_Lessons.h"
#include "Example_Stl.h"
#include "Example_Lesson_Io.h"
#include "Example_Lesson_Thread.h"
#include "AsExample_Lesson_Conversions.h"
#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include <random>

//------------------------------------------------------------------------------------------------------------------
class AsTutorial_Main
{
public:
	AsTutorial_Main();

	void Init();

private:
	void Templates_Example();
	void Regular_Expresion_Example();
	void Random_Shaffle_Example_Algoritms();

	APoint Point_Writte_Test;
	string Read_From_File;
	AsSimple_Timer Simple_Timer;
	AsExample_Lessons Example_Lessons;
	AsExample_Stl Example_Stl;
	AExample_Lesson_Io Example_Lesson_Io;
	AsExample_Lesson_Thread Example_Lesson_Thread;
	AsExample_Lesson_Conversions Example_Lesson_Conversions;

};
//------------------------------------------------------------------------------------------------------------------
