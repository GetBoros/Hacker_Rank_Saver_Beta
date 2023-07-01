#pragma once

#include "Templates.h"
#include "Living_Being.h"
#include "Point.h"

//------------------------------------------------------------------------------------------------------------------
class AsExample_Stl
{
public:
	~AsExample_Stl();
	AsExample_Stl();

	void List(bool is_assign);
	void Forward_List();
	void Linked_List(bool is_input, int enter_size);  // My_Bad_List_
	void Array();

	// Binar tree
	void Set();
	void Multi_Set();
	void Map();  // Store only unique elements
	void Multimap();  // Can Store non-unique elements
	void Stack();
	void Queue();

	void Sort_Algoritms();
	void Find_Find_If_Algoritms();
	void Copy_Copy_If_Algoritms();
	void Remove_if_Algoritms();
	void Find_Min_Max_Element_Algoritms();
	void Accumulate_Algoritms();
	void Mismatch_And_Equal_Algoritms();
	void Equal_Class_Predicat_Algoritms();
	void For_Each_Algoritms(bool is_bind);
	void Unique_Copy_Algoritms(bool is_unique_copy);

private:
	const bool Greater_Then_Zero_Binar(const int first, const int second);
	const void Show_Int(const int a);


};
//------------------------------------------------------------------------------------------------------------------
