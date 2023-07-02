#include "Tutorial_Main.h"

// AsTutorial_Main
AsTutorial_Main::AsTutorial_Main()
: Point_Writte_Test(5, 3, 1), Read_From_File("")
{
}
//------------------------------------------------------------------------------------------------------------------
void AsTutorial_Main::Init()
{
    // Example_Lesson_Conversions
    /*
    Example_Lesson_Conversions.Init();

    */

    Example_Lesson_Conversions.Init();

     //Example_Lessons.
    /*                                               Example_Lessons.
    // Example_Lessons.Predicate();
    // Example_Lessons.Catch_Excaption(true);  // Show how to throw and catch excaption(true to show ifstream excaption
    // Example_Lessons.Union();  // Maybe some day u can use this
    // Example_Lessons.Virtuals();  // Interface | Aggregation and Composition |
    // Example_Lessons.Functors();  // class with overwrited () example
    // Example_Lessons.Lambda();  // Lambda expression example
    // Example_Lessons.Smart_Pointer();
    */
    // Done
    
    // Standart || Templates || Library : STL
    /*                                    Standart || Templates || Library
    // Templates_Example();
    // Example_Stl.List(false);  // if u want to see assign need true
    // Example_Stl.Forward_List();  // Examples 
    // Example_Stl.Linked_List(false, 5);
    // Example_Stl.Array();
    // Example_Stl.Set();
    // Example_Stl.Multi_Set();
    // Example_Stl.Map();
    // Example_Stl.Multimap();
    // Example_Stl.Stack();  // First in last out
    // Example_Stl.Queue();  // Manny func examples and priority_queue

    // Example_Stl.Find_Find_If_Algoritms();();
    // Example_Stl.Copy_Copy_If_Algoritms();
    // Example_Stl.Remove_if_Algoritms();
    // Example_Stl.Accumulate_Algoritms();  // sum all data from one arr(vector) or else
    // Example_Stl.Mismatch_And_Equal_Algoritms();  // arr equals and mismatch examples
    // Example_Stl.Equal_Class_Predicat_Algoritms();  // Class equal with use lambda and other 
    // Example_Stl.For_Each_Algoritms(true);  // Copy arr to another arr with unique data
    // Example_Stl.Unique_Copy_Algoritms(bool is_unique_copy);  // if false unique if true unique_copy
    */
    // Done

    // Save Data to Files using ofstream : I/O Streams
    /*                                    Save Data to Files using ofstream
    // Example_Lesson_Io.Output_Stream(Point_Writte_Test, true);  // Save Class to file or enter your own data nums
    // Example_Lesson_Io.Input_Stream(Example_Lesson_Io.Reading_File_Type);  // Load data from file to object 
    // Example_Lesson_Io.Writte_Read_Objects(Point_Writte_Test);  // Write then read object
    // Example_Lesson_Io.FStream_Test(Point_Writte_Test);  // Write/Read Data || Objects if overwrited >> <<
    */
    // Done

    // Threads
    /*                                     Threads and Chronos
    // Example_Lesson_Thread.Main_Class_Examples();  // class threads examples  ||  Debug to understand || 1
    // Example_Lesson_Thread.Main_Mutex();  // examples three type of mutex     ||  Debug to understand || 2
    // Example_Lesson_Thread.Reference_Param();  // Reference_Param             ||  Debug to understand || 2
    */
    // Done
}
//------------------------------------------------------------------------------------------------------------------
void AsTutorial_Main::Templates_Example()
{
    int *pointer = new int(5);
    APrinter_Template<string> Printer_Template;
    ASmart_Pointer<int> smart_pointer = new int(5);
    AsType_Info<AExample_Lesson_Io> lesson_template(Example_Lesson_Io);  // info about class in < >

    lesson_template.Get_Type_Size();  // sizeof(type_class)
    lesson_template.Show_Type_Name();  // Show Template implementation

    Printer_Template.Print_Value("Hello World!!!");  // Show template specificator

    cout << "point on address:\t" << pointer << "\tValue:\t"<< *pointer << endl;  // Pointer example
    cout << "\t"<< *smart_pointer << endl;  // Smart pointer example

    delete pointer;
}
//------------------------------------------------------------------------------------------------------------------
void AsTutorial_Main::Regular_Expresion_Example()
{
    const int N = 6;
    string s = "Some people, when confronted with a problem, think "
        "\"I know, I'll use regular expressions.\" "
        "Now they have two problems.";

    // regues find regular expresion, looking matches ECMAScript, and with icase ignor upper and lower 
    regex self_regex("REGULAR EXPRESSIONS", regex_constants::ECMAScript | regex_constants::icase);
    regex word_regex("(\\w+)");  // find all words in my string
    regex long_word_regex("(\\w{7,})");
    string new_s = regex_replace(s, long_word_regex, "[$&]");
    ASlasher slasher("Regular Expression Examples");

    if (regex_search(s, self_regex) )  // if find matches true
        cout << "Text contains the phrase 'regular expressions'\n";

    auto words_begin = sregex_iterator(s.begin(), s.end(), word_regex);  // it on first word
    auto words_end = sregex_iterator();  // point on last position

    cout << "Found " << distance(words_begin, words_end) << " words\n";  // how much words we found

    cout << "Words longer than " << N << " characters:\n";

    for (sregex_iterator i = words_begin; i != words_end; ++i)
    {// show words longer that N = 6
        smatch match = *i;
        string match_str = match.str();

        if (match_str.size() > N)  // if string more then 6 print it
            cout << "  " << match_str << '\n';
    }

    cout << new_s << '\n';
}
//------------------------------------------------------------------------------------------------------------------
void AsTutorial_Main::Random_Shaffle_Example_Algoritms()
{
    int arr_1[] = { 1, 2, 3, 4, 5 };

    AsAction* action[] = {
        new ACat_Action(),
        new ADog_Action(),
        new ATea_Action(),
        new ASleep_Action()
    };

    srand(static_cast<unsigned int>(time(0) ) );

    shuffle(begin(action), end(action), default_random_engine( (int)time(0) ) );
    for (auto* it : action)
        it->Action();

    shuffle(begin(arr_1), end(arr_1), default_random_engine( (int)time(0) ) );
    for (auto it : arr_1)
        cout << it << " ";
    cout << endl;

    for (auto* it : action)
        delete it;
}
//------------------------------------------------------------------------------------------------------------------
