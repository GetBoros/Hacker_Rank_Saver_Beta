#pragma once

#include "Template_Specialization.h"
#include "Complex.h"
#include "Tutorial_Main.h"
#include "Saver.h"
#include "As_Life_Simulator.h"

typedef pair<int,int> p;
typedef vector<p> Available_Workshops;

//------------------------------------------------------------------------------------------------------------------
enum class ETask_Number: unsigned char
{
	Task_Undefined,

	Task_Print_Some_Text,
	Task_Read_Data_Type,
	Task_Condition_Statements,
	Task_Condition_For_Loop,
	Task_Update_Two_Integers,
	Task_Array_Double,
	Task_Operator_Overload,
	Task_Workshop_Attending,
	Task_Max_Of_Four,
	Task_Template_Specialization,

	Task_Last
};
//------------------------------------------------------------------------------------------------------------------
class AHacker_Rank_Tasks
{
public:
	AHacker_Rank_Tasks();

	void Init();
	void Task_Define();

	void Task_Print_Some_Text();
	void Task_Read_Data_Type();
	void Task_Condition_Statements();
	void Task_Condition_For_Loop();
	void Task_Update_Two_Integers();
	void Task_Array_Double();
	void Task_Operator_Overload();
	void Task_Workshop_Attending();
	void Task_Template_Specialization();

	int Task_Max_Of_Four();


private:
	ETask_Number Task_Number;
	int A, B;
	int Player_Number;
	string Player_Name, Slash;
	void File_Example_Input_Output();

	string ltrim(const string &str);
	string rtrim(const string &str);
	string Convert_To_Word(int n);

};
//------------------------------------------------------------------------------------------------------------------
