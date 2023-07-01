#include "Example_Lesson_Thread.h"

// AsExample_Lesson_Thread
void AsExample_Lesson_Thread::Main_Class_Examples()
{
    int num_1, num_2;
    int is_join_thread;
    int result_sum;

    Thread_First = thread([this, &result_sum](int a, int b)  // Second Thread
        {
            result_sum = Sum(a, b);

        }, 3, 6);

    Thread_Second = thread(&AsExample_Lesson_Thread::Do_Work, this, 200);  // Third Thread
    Do_Work(500);  // Main Thread
    Thread_First.join();
    Thread_Second.join();

    cout << AsTools::Slash_String << "\nEnter true or false:\n" <<AsTools::Slash_String << endl;
    cin >> is_join_thread;

    if (is_join_thread == 0)
        Thread_Third = thread(&AsExample_Lesson_Thread::Join_Or_Detach, this, is_join_thread);
    else
        Thread_Third = thread(&AsExample_Lesson_Thread::Join_Or_Detach, this, is_join_thread);

    Thread_Third.join();

    cout << "Enter a and b to take a solution:  " << endl;
    cin >> num_1 >> num_2;
    Thread_Four = thread(&AsExample_Lesson_Thread::Print_And_Sum, this, num_1, num_2, "Hello");
    Do_Work(500);  // Main Thread
    Thread_Four.join();

    cout << AsTools::Slash_String << "\nResult Sum:\t" << result_sum << endl <<AsTools::Slash_String << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Thread::Main_Mutex()
{
    Thread_First = thread(&AsExample_Lesson_Thread::Mutex_Lock_Guard, this, '*', true);
    Thread_Second = thread(&AsExample_Lesson_Thread::Mutex_Lock_Guard, this, '#', false);

    Thread_First.join();
    Thread_Second.join();

    Thread_Third = thread(&AsExample_Lesson_Thread::Task_Recursive_Mutex, this, 10);
    Thread_Four = thread(&AsExample_Lesson_Thread::Task_Recursive_Mutex, this, 10);

    Thread_Third.join();
    Thread_Four.join();
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Thread::Reference_Param()
{
    int num = 5;
    thread thread_first;

    thread_first = thread(&AsExample_Lesson_Thread::Ref_Multiply, this, ref(num) );  // use func ref 

    Do_Work(500);

    thread_first.join();  // Waiting result thread_first
    cout << num << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Thread::Do_Work(int milliseconds)
{
    int i;

    for (i = 0; i < 10; i++)
    {//cout << "Start Main Thread " << endl;

     // Show curr id thread and freeze to 1 sec
        cout << "ID Thread = \t" << this_thread::get_id() << "\t== Main_Thread ==\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(milliseconds) );
    }
    //cout << "End Main Thread" << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Thread::Join_Or_Detach(bool is_join_thread)
{
    Thread_First = thread(&AsExample_Lesson_Thread::Do_Work, this, 500);
    Thread_Second = thread(&AsExample_Lesson_Thread::Do_Work, this, 500);

    cout << "Start Main Thread " << endl;
    Do_Work(500);  // Main Thread
    cout << "End Main Thread" << endl;

    if (is_join_thread)
    {
        Thread_First.join();  // still work when we we wont go out from local space func Init();
        Thread_Second.join();  // still work when we we wont go out from local space func Init();
        cout << AsTools::Slash_String << "\njoin_thread succes:\n" <<AsTools::Slash_String << endl;
    }
    else
    {
        Thread_First.detach();  // stop work when we out from local space func Init();
        Thread_Second.detach();  // stop work when we out from local space func Init();
        cout << AsTools::Slash_String << "\ndetach_thread succes:\n" <<AsTools::Slash_String << endl;
    }
    cout << "Go out from func Init() " << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Thread::Print_And_Sum(int a, int b, string msg)
{
    cout << msg << endl;
    this_thread::sleep_for(chrono::milliseconds(AsConfig::Thread_Sleep_For) );
    cout << "=====\t" << " Do_Work Started \t =====" << endl;
    this_thread::sleep_for(chrono::milliseconds(AsConfig::Thread_Sleep_For) );
    cout << " a + b = " << a + b << endl;
    this_thread::sleep_for(chrono::milliseconds(AsConfig::Thread_Sleep_For) );
    cout << "=====\t" << " Do_Work Stopped\t =====" << endl;
}
//------------------------------------------------------------------------------------------------------------------
int AsExample_Lesson_Thread::Sum(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(AsConfig::Thread_Sleep_For) );
    cout << "ID Thread = \t" << this_thread::get_id() << "\t==========Sum Started==========" << endl;

    this_thread::sleep_for(chrono::milliseconds(AsConfig::Thread_Sleep_For) );
    cout << "ID Thread = \t" << this_thread::get_id() << "\t==========Sum Started==========" << endl;

    return a + b;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Thread::Ref_Multiply(int &a)
{
    this_thread::sleep_for(chrono::milliseconds(AsConfig::Thread_Sleep_For) );
    cout << "ID Thread: = \t" << this_thread::get_id <<  endl;
    a = a *  2;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Thread::Mutex_Lock_Guard(char ch, bool is_uniqe_lock)
{
    int i, j;
    unique_lock<mutex> u_lock(Mutex, defer_lock);  // with defer lock we need to lock self

    this_thread::sleep_for(chrono::milliseconds(AsConfig::Thread_Sleep_For) );
    //Mutex.lock();  // if we have guard this don`t need

    if (!is_uniqe_lock)
    {
        { // lock_guard example
            lock_guard<mutex> guard(Mutex);
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    cout << ch;
                    this_thread::sleep_for(chrono::milliseconds(10));
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    else
    {
        u_lock.lock();
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 10; j++)
            {
                cout << ch;
                this_thread::sleep_for(chrono::milliseconds(10));
            }
            cout << endl;
        }
        cout << endl;
        u_lock.unlock();
    }

    //Mutex.unlock();
    this_thread::sleep_for(chrono::milliseconds(2000) );
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lesson_Thread::Task_Recursive_Mutex(int recursive_calls)
{
    Rec_Mutex.lock();
    cout << recursive_calls << " ";
    this_thread::sleep_for(chrono::milliseconds(50) );

    if (recursive_calls <= 1)
    {
        cout << endl;
        Rec_Mutex.unlock();
        return;
    }

    recursive_calls--;
    Task_Recursive_Mutex(recursive_calls);
    Rec_Mutex.unlock();
}
//------------------------------------------------------------------------------------------------------------------
