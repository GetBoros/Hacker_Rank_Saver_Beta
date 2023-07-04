#include "As_Life_Simulator.h"

// AsHuman
AsHuman::~AsHuman()
{
}
//------------------------------------------------------------------------------------------------------------------
AsHuman::AsHuman()
	:Is_Male(true), Age(0.0), Height(0.0), Weight(0.0), Body_Fats(10000.0)
{
}
//------------------------------------------------------------------------------------------------------------------
AsHuman::AsHuman(bool is_male, double age, double weight, double height)
	: Is_Male(is_male), Age(age), Weight(weight), Height(height), Body_Fats(10000.0)
{
}
//------------------------------------------------------------------------------------------------------------------
const void AsHuman::Eat(AFood &food)
{
	Body_Fats = Body_Fats + food.Get_Calories();
}
//------------------------------------------------------------------------------------------------------------------
void AsHuman::Sleep()
{
}
//------------------------------------------------------------------------------------------------------------------
bool AsHuman::Spend_Time(double &time)
{
double cal_per_hour;
double cal_per_min;
	if (Body_Fats <= 500.0)  // if less then 500 character die
		return false;
	
	cal_per_hour = Get_Basal_Metabolic_Rate() / 24.0;  // calories destroi per hour
	cal_per_min = cal_per_hour / 60;  // calories destroi per min

	if (time > 1.0)
		Body_Fats = Body_Fats - (cal_per_hour * time);
	else
		Body_Fats = Body_Fats - (cal_per_min * time);

	return true;
}
//------------------------------------------------------------------------------------------------------------------
double AsHuman::Get_Basal_Metabolic_Rate() const
{
	double BMR;  // Basal Metabolic Rate
	const double activity_sedentary= 1.2;  // minimal or no physical activity
	const double activity_light= 1.375;  // moderate exercise or 1-3 times per week
	const double activity_moderately= 1.55;  // training or exercising 3-5 times a week
	const double activity_high= 1.725;  // intensive training or classes 6-7 times a week
	const double activity_very_high= 1.9;  // physically active work or intensive training every day

	// Ratio for man
	const double man_metabolism = 66.0;
	const double man_weight_ratio = 13.75;
	const double man_height_ratio = 5.0;
	const double man_age_ratio = 6.75;

	// Ratio for woman
	const double woman_metabolism = 655.0;
	const double woman_weight_ratio = 9.6;
	const double woman_height_ratio = 1.8;
	const double woman_age_ratio = 4.7;

	if (Is_Male)
		BMR = man_metabolism + (man_weight_ratio * Weight) + (man_height_ratio * Height) - (man_age_ratio * Age);
	else
		BMR = woman_metabolism + (woman_weight_ratio * Weight) + (woman_height_ratio * Height) - (woman_age_ratio * Age);

	return BMR;
}
//------------------------------------------------------------------------------------------------------------------




// As_Life_Simulator
As_Life_Simulator::~As_Life_Simulator()
{
}
//------------------------------------------------------------------------------------------------------------------
As_Life_Simulator::As_Life_Simulator()
{
}
//------------------------------------------------------------------------------------------------------------------
void As_Life_Simulator::Init()
{
	bool is_human_still_alive = true;
	double spend_time = 0.15;  // 0.15 min | 1.15 hour and 15 min
	AFood breakfast(124, 100, 20);  // need 1600 | Fats 70% 124g | Proteins 25% 100g | vegtales 5% 20g |
	AsHuman john(true, 32.0, 60.0, 185.0);

	while (is_human_still_alive)
	{// 

		john.Eat(breakfast);  // can be only one per day
		is_human_still_alive = john.Spend_Time(spend_time);
		john.Sleep();
		
	}
	cout << "You are afk" << endl;
}
//------------------------------------------------------------------------------------------------------------------




// AsMacronutrients
AsMacronutrients::AsMacronutrients(double fats, double proteins, double carbohydrates)
: Fats(fats), Proteins(proteins), Carbohydrates(carbohydrates)
{
}
//------------------------------------------------------------------------------------------------------------------




// AFood
AFood::AFood(double fats, double proteins, double carbohydrates)
: AsMacronutrients(fats, proteins, carbohydrates)
{

}
//------------------------------------------------------------------------------------------------------------------
double AFood::Get_Calories()
{
	Fats = Fats * 9.0;  // Get Calories
	Proteins = Proteins * 4.0;
	Carbohydrates = Carbohydrates * 4.0;

	return Fats + Proteins + Carbohydrates;
}
//------------------------------------------------------------------------------------------------------------------
