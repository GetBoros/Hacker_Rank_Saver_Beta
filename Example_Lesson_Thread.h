#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------------
class AsExample_Lesson_Thread
{
public:
	void Main_Class_Examples();
	void Main_Mutex();
	void Reference_Param();

private:
	thread Thread_First;  // 16
	thread Thread_Second;
	thread Thread_Third;
	thread Thread_Four;
	mutex Mutex;  // 80
	recursive_mutex Rec_Mutex;  // 80

	void Do_Work(int milliseconds);
	void Join_Or_Detach(bool is_join_thread);
	void Print_And_Sum(int a, int b, string msg);
	int Sum(int a, int b);
	void Ref_Multiply(int &a);
	void Mutex_Lock_Guard(char ch, bool is_uniqe_lock = false);
	void Task_Recursive_Mutex(int recursive_calls);
};
//------------------------------------------------------------------------------------------------------------------
