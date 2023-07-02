#pragma once

#include "Config.h"

//-----------------------------------------------------------------------------------------------------------
class AsHuman
{
public:
	~AsHuman();
	AsHuman();
	AsHuman(bool is_male, double age, double weight, double height);

	double Get_Basal_Metabolic_Rate() const;
	bool Spend_Time(double &time);

private:

	bool Is_Male;
	double Age;
	double Weight;
	double Height;

	double Body_Fats;  // 10 000 Callories
	
};
//-----------------------------------------------------------------------------------------------------------
class As_Life_Simulator
{
public:
	~As_Life_Simulator();
	As_Life_Simulator();

	void Init();

private:


	// Tasks

	/*
	
	

	1. Dialy Diet | Weakly
V	1.1. Calorie requirement per day
V	1.1. Body_Fats base for creating human, 
	1.1.1 Fat, proteins, carbohydrates || class Macronutrients | class parent Nutrients 
	1.1.2 Vitamins
	1.1.3 Minerals
	1.1.4 Water 
	1.1.5 Fibres, or fiber

V	2. Need Class Consumer || Human | Else
	2. Character Creator | Avatar
	2. Consume Fats: | carbohydrates
	2. - Human has: Fats what need to survive
V	2. - Human can die if fats less then 500
	2. - Human has: Base Fats per creating class
	2. - Human has: Muscle that consume calories

	3. Mechanics
V	3. When human fats = 0 its death or if < 500
V	3. Some period of time destoy Calories to survive if 1600 per day / 24 hours
	3. Action, what spending times, and raise activity per day
	3. Action, eat food, drink water else, raise calories, fats, hidration
	3. Action, shoping: use time, money, raise activity, else
	3. Auto schedule what can be added
	*/


};
//-----------------------------------------------------------------------------------------------------------
