#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------------
class APoint
{
public:
	APoint();
	APoint(int x, int y);
	APoint(int x, int y, int z);

	APoint &operator ++();  // operator ++(A)
	APoint &operator ++(int value);  // A operator ++(B)
	APoint &operator --();
	APoint &operator --(int value);
	APoint &operator =(const APoint &other);  // A.operator = (B)
	APoint &operator +(const APoint &other);  // this.operator = (B)
	APoint &operator -(const APoint &other);  // this.operator = (const &B)
	APoint &operator *(const APoint &other);
	APoint &operator /(const APoint &other);
	bool operator ==(const APoint &other);  // Overload 
	bool operator !=(const APoint &other);
	int &operator [](int index);

	friend void Point_Change_X(APoint &point);

	void Print();
	int Get_X() const;
	int Get_Y() const;

	int Arr[AsConfig::Point_Array_Length];

private:
	int X, Y, Z;

	friend ostream &operator<<(ostream &os, const APoint &point);
	friend istream &operator>>(istream &is, APoint &point);
};
//------------------------------------------------------------------------------------------------------------------
