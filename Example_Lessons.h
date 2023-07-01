#pragma once

#include "Messenger.h"
#include "Living_Being.h"
#include "Bicycle.h"
#include "Image.h"
#include "Functor_Example.h"
#include "Templates.h"

//------------------------------------------------------------------------------------------------------------------
class AsLesson_Exception : public exception
{
public:
	AsLesson_Exception(const char *msg, int Data_State);

	int Get_Data_State();

private:
	int Data_State;
};
//------------------------------------------------------------------------------------------------------------------
union UUnion_Types
{
	short int a;
	int b;
	float c;
};
//------------------------------------------------------------------------------------------------------------------
class AsExample_Lessons
{
public:
	AsExample_Lessons();

	UUnion_Types Union_Types;

	void Catch_Excaption(bool is_ifstream_example);
	void Throw_Excaption(int value);
	void Union();
	void Virtuals();
	void Inner_Classes();
	void Functors();
	void Lambda();
	void Predicate();
	void Smart_Pointer();

private:
	AHuman Human;
	AExtramural_Student Extramural_Student;

	void Vector_Sort(vector<int> &vec_1, vector<function<void(int)> > &func_vector);
	void Anonim_Func(vector<int> &vec_1, function<void(int)> func_vector);
	void Sort_Whole(int bar);
	void Sort_Range(int num);

	const bool Greater_Then_Zero(const int is_greater);
	const bool Lower_Then_Zero(const int is_greater);
};
//------------------------------------------------------------------------------------------------------------------
