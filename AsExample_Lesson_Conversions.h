#pragma once

#include "Living_Being.h"

//-------------------------------------------------------------------------------------------------------------------------------
enum class E { ONE = 1, TWO, THREE };
//-------------------------------------------------------------------------------------------------------------------------------
enum EU { ONE = 1, TWO, THREE };
//-------------------------------------------------------------------------------------------------------------------------------
class AsType
{
public:
	~AsType();
	AsType();

	const char *hello() const;
	void f(int v) const;

	int I;
	int M = 42;
	
	static const void St_Type_Info();
};
//-------------------------------------------------------------------------------------------------------------------------------
class AType_Child: public AsType
{
public:
	~AType_Child();
	AType_Child();

	const char *hello() const;
};
//-------------------------------------------------------------------------------------------------------------------------------
class AsExample_Lesson_Conversions
{
public:
	~AsExample_Lesson_Conversions();
	AsExample_Lesson_Conversions();

	void Init();

private:
	void Conversions_Examples();
	void Const_Cast_Conversions_Examples();
	void Static_Cast_Conversions_Examples();
	void Reinterpret_Cast_Conversions_Examples();
	void Character_Literal_Examples();

	void Type_Get_Info(const AsType *type);

	void Value_Categories();
	int Get_X();
	void Lambda_Expressions();
	void Lambda_Few_Examples_How_To_Use();

	int X;
	int Y;
};
//-------------------------------------------------------------------------------------------------------------------------------




// Conversions Tutorial
/*

Implicit Conversion 
Explicit Conversion
User-Defined Conversions
Type Traits

// Special operators
	static_cast  // converts one type to another related type
	dynamic_cast // converts within inheritance hierarchies
	const_cast  // adds or removes cv-qualifiers
	reinterpret_cast  // converts type to unrelated type
	C-style cast   // converts one type to another by a mix of static_cast, const_cast, and reinterpret_cast
	new  // creates objects with dynamic storage duration
	delete  // destructs objects previously created by the new expression and releases obtained memory area
	sizeof  // queries the size of a type
	sizeof...  // queries the size of a parameter pack (since C++11)
	typeid  // queries the type information of a type
	noexcept  // checks if an expression can throw an exception (since C++11)
	alignof  // queries alignment requirements of a type (since C++11)

// Special operators

*/