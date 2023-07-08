#pragma once

//-----------------------------------------------------------------------------------------------------------
class AEgg
{
public:
	~AEgg();
	AEgg();

private:
	const int Grams;
	const int Energy_Kcal;
	const int Energy_KJ;
	const double Fat;
	const double Protein;

	const double Vitamin_A, Vitamin_D, Vitamin_B2, Vitamin_B12, Vitamin_Folate;
	const double Vitamin_Biotin, Vitamin_Pantothenic_Acid, Vitamin_Choline;

	//Minerals
	const double Phosphorus, Iodine, Selenium;
};
//-----------------------------------------------------------------------------------------------------------
