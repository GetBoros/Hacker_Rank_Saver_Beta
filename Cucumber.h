#pragma once

//-----------------------------------------------------------------------------------------------------------
class ACucumber
{
public:
	virtual ~ACucumber();
	ACucumber();

private:
	const int Water;
	const int Grams;
	const int Energy_Kcal;
	const double Fat;
	const double Protein;
	const double Carbohydrates;

	// Vitamins
	const double Vitamin_K, Vitamin_C;

	//Minerals
	const double Beta_Carotene, Potassium, Magnesium;

};
//-----------------------------------------------------------------------------------------------------------
