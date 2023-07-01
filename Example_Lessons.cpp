#include "Example_Lessons.h"

// AsLesson_Exception
AsLesson_Exception::AsLesson_Exception(const char *msg, int data_state)
: exception(msg), Data_State(data_state)
{
}
//------------------------------------------------------------------------------------------------------------------
int AsLesson_Exception::Get_Data_State()
{
    return Data_State;
}
//------------------------------------------------------------------------------------------------------------------




// AsExample_Lessons
AsExample_Lessons::AsExample_Lessons()
: Union_Types{}
{
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Catch_Excaption(bool is_ifstream_example)
{
    if (is_ifstream_example)
    {
        ifstream fin;
        fin.exceptions(ifstream::badbit | ifstream::failbit);

        try
        {
            AsConfig::Text_Print_To_Console("Try open file\n");
            fin.open(AsConfig::Path);
            AsConfig::Text_Print_To_Console("File open succes\n");
            fin.close();
        }
        catch (const ifstream::failure &ex)
        {
            AsConfig::Text_Print_To_Console(ex.what(), true, ":\t Fatal Error\n");
            cout << ex.code() << endl;
        }
    }
    else
    {
        try
        {
            Throw_Excaption(1);  // Func with throw 
        }
        catch (AsLesson_Exception &ex)  // We can change class exception to int or else but what throw need to be excactli
        {
            AsConfig::Text_Print_To_Console(ex.what(), true, "\nCatch Exception block one\n");
            cout << "Data State: " <<ex.Get_Data_State() << endl;

        }
        catch (const char *ex)
        {
            AsConfig::Text_Print_To_Console(ex, true, "\nCatch Exception block second\n");
        }
        catch (...)
        {
            AsConfig::Text_Print_To_Console("Something wrong\n", true, "Catch Exception block third\n");
        }
    }
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Throw_Excaption(int value)
{
    if (value > 21)
        throw exception("Num > than 20");  // exception can be int or other class(object)

    if (value == 21)
        throw "Num == 21";  // exception can be int or other class(object)

    if (value == 1)
        throw AsLesson_Exception("asd", value);
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Union()
{
    Union_Types.a = 5;
    Union_Types.b = 40000;
    Union_Types.c = 23.325f;

    cout << Union_Types.c << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Virtuals()
{
    AsLiving_Being *human; 
    ABrakets_Msg msg("Hello");
    APrinter printer;
    ASimple_Bicycle simple_bicycle;
    ASport_Bicycle sport_bicycle;
    AMan man;

    cout << AsTools::Slash_String << endl;
    printer.Print(&msg);

    man.Ride_On(simple_bicycle);
    man.Ride_On(sport_bicycle);

    human = &Human;
    human->Speak();

    human = &Extramural_Student;
    Human.Speak_Like(human);
    cout << AsTools::Slash_String << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Inner_Classes()
{
    AImage image;

    image.Get_Image_Info();  // Inner Class how use and else
    Human.Think();  // Aggregation and Composition*
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Functors()
{
    AFunctor_Example functor_example;  // Class func with overwrited ()
    int result;
    int arr_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << AsTools::Slash_String << endl;
    functor_example();

    cout << AsTools::Slash_String << endl;
    result = functor_example(2, 5);

    cout << AsTools::Slash_String << endl;

    /*							STD: Lambda, Thread, Chrono								*/	
    for (auto &it : arr_1)
        functor_example(it);

    functor_example.Show_Event_Sum();
    functor_example.Show_Event_Count();
    cout << result << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Lambda()
{
    bool is_done;
    vector<int> vec_1;
    vector<function<void(int)> > vec_2;
    function<void(int)> f;

    //exmaples lambda
    []()->int { };

    vec_1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // init vector

    vec_2.emplace_back( [this] (int num) { Sort_Whole(num); } );  // if whole num true emplace back to vector
    vec_2.emplace_back( [this] (int num) { Sort_Range(num); } );  // if num in range true emplace back to vector

    // Lambda expressions
    is_done = false;
    auto liam = [&is_done](){ is_done = true; };  // set is_done to true with help &
    liam();
    auto alpha = [](){ return 2.323; };
    auto beta = alpha();

    Vector_Sort(vec_1, vec_2);  // Or sort Sort_Range ** [this](int a) { Sort_Whole(a); } 
    // Add anonim func
    Anonim_Func(vec_1, [](int num){ cout << "Anonim func:\t" << num << endl; } );
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Predicate()
{
    int test_done;
    int lower_then_zero;
    int greater_then_zero;
    vector<int> vec;
    vector<AStudent> student_vector;
    ASlasher aslasher("Queue Example\tPriority_Queue");
    AsType_Info< vector<AStudent> > type_info(student_vector);  // show info about student_vector

    vec = { 1, -2, 3, -4, 5, -6, 7, -8, 9, -10 };
    student_vector = {
        AStudent("Andrey", 181),
        AStudent("Masha", 170),
        AStudent("Katy", 169),
        AStudent("Roma", 198),
    };

    // if score more then 180 count_if return true with help overwrited operator in class AStunden
    test_done = (int)count_if(student_vector.begin(), student_vector.end(), student_vector.front() );

    // Predicat true cout_if change result++, else do nothing || Example_Lesson_Greater_Then_Zero
    lower_then_zero = (int)count_if(vec.begin(), vec.end(), [this](int value)
        {
            bool res = Lower_Then_Zero(value);
            return res;
        } );

    // Predicat true cout_if change result++, else do nothing || Example_Lesson_Greater_Then_Zero
    greater_then_zero = (int)count_if(vec.begin(), vec.end(), [this](int value)
        {
            bool res = Greater_Then_Zero(value);
            return res;
        } );

    cout << test_done << "\t = Student(s) done test" << endl;
    cout << lower_then_zero << " = lower_then_zero nums || and greater \t" << boolalpha << greater_then_zero << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Smart_Pointer()
{
    int i;
    int size;
    int *arr; 

    cin >> size;
    arr = new int[size];

    shared_ptr<int[]> s_ptr(arr);  // Add dynamic arr to Smart Pointer

    for (i = 0; i < size; i++)
    {
        s_ptr[i] = rand() % 10;  // Random init arr num
        cout << s_ptr[i] << endl;
    }
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Vector_Sort(vector<int> &vec_1, vector<function<void(int)> > &vec_2)
{
    for (auto &it : vec_1)
        for (auto &it_fv : vec_2)
            it_fv(it);
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Anonim_Func(vector<int> &vec_1, function<void(int)> func)
{
    for (auto &it: vec_1)
        func(it);
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Sort_Whole(int bar)
{
    if (bar % 2 == 0)
        cout << "Whole: \t" << bar << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Lessons::Sort_Range(int num)
{
    if (num > 3 && num < 7)
        cout << "Range: \t" << num << endl;
}
//------------------------------------------------------------------------------------------------------------------
const bool AsExample_Lessons::Greater_Then_Zero(const int is_greater)
{
    bool result = (bool)(is_greater > 0);
    return result;
}
//------------------------------------------------------------------------------------------------------------------
const bool AsExample_Lessons::Lower_Then_Zero(int is_lower)
{
    bool result = (bool)(is_lower > 0);
    return result;
}
//------------------------------------------------------------------------------------------------------------------
