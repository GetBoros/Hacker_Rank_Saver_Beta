#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------------
class ACap
{// ACap, AHuman and AsBrain example of Aggregation

public:
	ACap();

	string Get_Color();

private:
	string Color = "Red";
};
//------------------------------------------------------------------------------------------------------------------
class AsLiving_Being
{
public:
	virtual void Eat() = 0;
	virtual void Sleep() = 0;
	virtual void Speak() = 0;

};
//------------------------------------------------------------------------------------------------------------------
class AHuman : public AsLiving_Being
{// AHuman and AsBrain example of Composition 

public:
	AHuman();
	AHuman(string name);
	AHuman(string name, int age);

	virtual void Eat();
	virtual void Sleep();
	virtual void Speak();

	void Think();
	void Speak_Like(AsLiving_Being *living_being);
	void Set_Name(string name);
	void Set_Age(int age);
	int Get_Human_Counts();

	string Get_Name() const;
	int  Get_Age() const;

	int Test = 42;

private:
	class AsBrain
	{// Внутренний класс, выполняющий делегирование
	public:
		AsBrain();

		void Think(AHuman &human);  // Вызов метода исполнителя

	private:

	};

	string Name;
	int Age;
	ACap Cap;
	AsBrain Brain;  // Делегат задачи

	void Inspect_Cap();

	static int Human_Counts;
};
//------------------------------------------------------------------------------------------------------------------
class AStudent : public AHuman
{
public:
	AStudent();
	AStudent(string name, int score);
	AStudent(string name, int score, int age);

	virtual void Eat();
	virtual void Sleep();
	virtual void Speak();

	bool operator()(const AStudent &stud)
	{
		return stud.Score > 180;
	};

	int Score;
	void Learn();
	string Group();
private:
};
//------------------------------------------------------------------------------------------------------------------
class AExtramural_Student : public AStudent
{
public:
	AExtramural_Student();

	virtual void Eat();
	virtual void Sleep();
	virtual void Speak();

	void Learn();

private:
};
//------------------------------------------------------------------------------------------------------------------
class AProfessor : public AExtramural_Student
{
public:
	AProfessor();

	virtual void Eat();
	virtual void Sleep();
	virtual void Speak();

	string Subject();

private:
};
//------------------------------------------------------------------------------------------------------------------
