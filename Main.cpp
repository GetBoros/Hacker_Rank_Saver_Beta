#include "Main.h"

//------------------------------------------------------------------------------------------------------------------
Available_Workshops *initialize(int *start_time, int *duration, int n)
{
    auto aw = new Available_Workshops(n);

    for(int i = 0; i < n; i++)
    {
        aw->at(i).first = start_time[i];
        aw->at(i).second = start_time[i]+duration[i];
    }
    return aw;
}
//------------------------------------------------------------------------------------------------------------------
int CalculateMaxWorkshops(Available_Workshops* data)
{
    sort(data->begin(), data->end(), [](const p &a, const p &b) { return a.second < b.second; });

    int f = 0, res = 0;

    for(int i = 0; i < data->size(); i++){
        if(data->at(i).first >= f)
        {
            res++;
            f = data->at(i).second;
        }
    }
    return res;
}//------------------------------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------------------------------
int main()
{
    //AExample_Lesson_Io example_lesson_io;
    //example_lesson_io.Output_Input_Binary();

    chrono::steady_clock::time_point start, end;
    chrono::duration<float> duration;

    start = chrono::high_resolution_clock::now();

    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");

    AsSaver saver;
    saver.Init();

    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Program life time: = (" << duration.count() << " Seconds!!!)" << endl;


    //As_Life_Simulator life_simulator;
    //
    //if (true)
    //    life_simulator.Init();


    // Temp
    /*
    //AHacker_Rank_Tasks hacker_rank_tasks;
    //AsTutorial_Main tutorial_main;
    */

    // Project Saver
    /*
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");

    AsSaver saver;
    saver.Init();
    */

    // Task
    /*
    
    */

    // AsTutorial_Main
    /*
    AsTutorial_Main tutorial_main;
    tutorial_main.Init();
    */

    // AHacker_Rank_Tasks
    /*
    //hacker_rank_tasks.Task_Define();
    //hacker_rank_tasks.Task_Enter_Number();
    //hacker_rank_tasks.Task_Print_Some_Text("Enter Tusk Number");
    //hacker_rank_tasks.Task_Read_Data_Type();
    //hacker_rank_tasks.Task_Condition_Statements();
    //hacker_rank_tasks.Task_Condition_For_Loop();
    //hacker_rank_tasks.Task_Update_Two_Integers();  // cin 4 5 cout 9 1
    //hacker_rank_tasks.Task_Array_Double(); 
    //hacker_rank_tasks.Task_Operator_Overload();
    //hacker_rank_tasks.Task_Workshop_Attending();
    //hacker_rank_tasks.Task_Template_Specialization();
    //int ans = hacker_rank_tasks.Task_Max_Of_Four();
    // Self Prod
    //hacker_rank_tasks.File_Example_Input_Output();
    */

    return 0;
}
//------------------------------------------------------------------------------------------------------------------





// AHacker_Rank_Tasks
AHacker_Rank_Tasks::AHacker_Rank_Tasks()
 : Task_Number(ETask_Number::Task_Undefined), Player_Name(""), Player_Number(0), A(0), B(0),
   Slash("//----------------------------------------------------------------------------------------------------")
{
}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::Init()
{
}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::Task_Define()
{
    if (Task_Number == ETask_Number::Task_Last)
        return;

    if (Task_Number != ETask_Number::Task_Undefined)
    {
        cout << Slash << endl;
        AsConfig::Print_Player_Query();
        cin >> Player_Number;
        cout << Slash << endl;
        Task_Number = (ETask_Number)Player_Number;
    }

    switch (Task_Number)
    {
    case ETask_Number::Task_Undefined:
        Task_Number =  ETask_Number::Task_Print_Some_Text;
        break;

    case ETask_Number::Task_Print_Some_Text:
        Task_Print_Some_Text();
        break;

    case ETask_Number::Task_Read_Data_Type:
        Task_Read_Data_Type();
        break;

    case ETask_Number::Task_Condition_Statements:
        Task_Condition_Statements();
        break;

    case ETask_Number::Task_Condition_For_Loop:
        Task_Condition_For_Loop();
        break;

    case ETask_Number::Task_Update_Two_Integers:
        Task_Update_Two_Integers();
        break;

    case ETask_Number::Task_Array_Double:
        Task_Array_Double();
        break;

    case ETask_Number::Task_Operator_Overload:
        Task_Operator_Overload();
        break;

    case ETask_Number::Task_Workshop_Attending:
        Task_Workshop_Attending();
        break;

    case ETask_Number::Task_Max_Of_Four:
        Task_Max_Of_Four();
        break;

    case ETask_Number::Task_Template_Specialization:
        Task_Template_Specialization();
        break;

    case ETask_Number::Task_Last:
        break;

    default:
        //AsConfig::Throw();
        break;
    }

    Task_Define();
}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::Task_Print_Some_Text()
{
    const char *text;
    int i;
    string greeting;

    cout << "Enter your Name and Lucky Num: \n";
    cin >> Player_Name >> Player_Number;

    greeting = "\t|| Hello, " + Player_Name + "!";  // Конкатенация строк
    text = "Lucky Number";

    for (i = 0; i < 3; i++)
    {
        cout<<Slash<<endl;

        if (i == 0)
        {
            cout<<"Name: \t\t\t";
            cout<<greeting<<endl;
        }

        if (i == 1)
        {
            printf("Task to print some Text: \t");
            printf("|| This is your %s, %d\n", text, Player_Number);
        }
    }

    Task_Define();

}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::Task_Read_Data_Type()
{// Task Three
    int i;
    long l;
    char c;
    float f;
    double d;

    cout << "Task_Read_Data_Type - Sample Input 3 12345678912345 a 334.23 14049.30493" << endl;
    scanf_s("%d %ld %c", &i, &l, &c, (char)sizeof(c) );  // Sample Input 3 12345678912345 a 334.23 14049.30493
    scanf_s("%f %lf", &f, &d);
    printf("%d\n%ld\n%c\n%.3f\n%.9lf\n", i, l, c, f, d);  // Output

    Task_Define();
}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::Task_Condition_Statements()
{
    int n;
    string n_temp;

    cout << "Task_Condition_Statements - Exmpl ltrim and rtrim (space 5 space) " << endl;

    cin >> n_temp;  // Считывать целую строку, включая пробелы, из входного потока.

    //getline(cin, n_temp);  // Считывать целую строку, включая пробелы, из входного потока.

    n = stoi(ltrim(rtrim(n_temp) ) );  // Преобразования строки в целочисленное значение.

    if (n >= 1 && n <= 9)
        cout << Convert_To_Word(n)<< endl;
    else
        cout << "Greater than 9" << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::Task_Condition_For_Loop()
{
    int start, end;

    cout << "Task_Condition_For_Loop: Exmpl from 1 to 12" << endl;
    cin >> start >> end;

    for (int i = start; i <= end; i++)
    {
        if (i >= 1 && i <= 9)
            cout << Convert_To_Word(i) << endl;
        else 
            if (i % 2 == 0)
                cout << "even" << endl;
            else
                cout << "odd" << endl;
    }
}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::Task_Update_Two_Integers()
{
    cout << "Task_Update_Two_Integers with *pointers: exmp 2 2" << endl;
    scanf_s("%d %d", &A, &B);

    int *pa, *pb;  // Two pointers

    pa = &A;  // Присваивается адрес переменной А
    pb = &B;


    int sum = *pa + B;
    int diff = abs(*pa - B);

    *pa = sum;
    B = diff;

    cout << "Result: Sum & Diff:" << endl;
    printf("%d %d \n", A, B);
}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::Task_Array_Double()
{
    int rows, colums;
    int i, j, k;

    cout << "Task_Array_Double 2D - Enter Rows and Colums_Query: Exmp 2 5" << endl;
    cin >> rows >> colums;  // Задаем двумерный массив

    vector<vector<int>> arr(rows);  // Создаем двумерный массив

    for (i = 0; i < rows; ++i)  // Создаем масив указателей из ввода
    {
        cout << "Capacity colums: " << endl;
        cin >> k;  // Указиваем количество ячеек в colums

        arr[i].resize(k);  // Меняем количество

        cout << "Enter Data to colums: Example if capacity 3 - 5 1 4 " << endl;
        for (j = 0; j < k; ++j)
            cin >> arr[i][j];  // Записиваем данные в colums
    }

    for (int colums_query = 0; colums_query < colums; ++colums_query )
    {
        cout << "Get Access to Colums Data in a Rows - Example: [1][2] " << endl;
        cin >> i >> j;  // запраштваем данные через ввод [0][2]
        cout << arr[i][j] << endl;
    }
}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::Task_Operator_Overload()
{
    AsComplex Complex_1, Complex_2;
    AsComplex Complex_Sum;
    string str_1,str_2;

    cout << "In 4 num to find complex: Example 3+i4 : " << endl;
    cin >> str_1;
    cin >> str_2;

    Complex_1.Input(str_1);  // Преобразуем строку в переменые А, B класса Complex
    Complex_2.Input(str_2);

    Complex_Sum = Complex_1 + Complex_2;  // Ипользуем перегруженый оператор "+"

    cout << Complex_Sum << endl;

    cout << "Working with operator overload!" << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::Task_Workshop_Attending()
{
    int i;
    int numbers_of_workshops;

    Available_Workshops *available_workshops;

    cout << "Task_Workshop_Attending - Example 6 \t 1 3 0 5 5 8 \t 1 1 6 2 4 1" << endl;
    cin >> numbers_of_workshops;
    int *start_time = new int[numbers_of_workshops];
    int *duration = new int[numbers_of_workshops];


    for(i = 0; i < numbers_of_workshops; i++)  // 1 3 0 5 5 8
        cin >> start_time[i];

    for(i = 0; i < numbers_of_workshops; i++) // 1 1 6 2 4 1
        cin >> duration[i];

    available_workshops = initialize(start_time, duration, numbers_of_workshops);

    cout << CalculateMaxWorkshops(available_workshops) << endl;

    delete[] start_time;
    delete[] duration;
}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::Task_Template_Specialization()
{
    int i;
    int index_1, index_2;
    int t;
    
    std::cout << "Task_Template_Specialization: \nEnter how many lines: ";
    cin >> t;

    if (t == 0)
        return;

    for (i = 0; i != t; ++i)
    {
        cout << "Choose two number from 0 - 2 : \nColor and Fruit: ";

        cin >> index_1;
        cin >> index_2;

        cout << Slash << endl;
        cout << Traits<EColor>::Name(index_1) << "";
        cout << Traits<EFruit>::Name(index_2) << "\n";
        
        if (i != (t - 1) )
            cout << Slash << endl;
    }
}
//------------------------------------------------------------------------------------------------------------------
int AHacker_Rank_Tasks::Task_Max_Of_Four()
{
    int a, b, c, d;
    cout << "Task_Max_Of_Four - Input 4 nums: \n";
    scanf_s("%d %d %d %d", &a, &b, &c, &d);


    int max_value = a;

    if (b > max_value) {
        max_value = b;
    }

    if (c > max_value) {
        max_value = c;
    }

    if (d > max_value) {
        max_value = d;
    }

    printf("%d\n", max_value);

    return max_value;
}
//------------------------------------------------------------------------------------------------------------------
void AHacker_Rank_Tasks::File_Example_Input_Output()
{
    char processedOutput[AsConfig::Max_Char_Symbol];
    char input[AsConfig::Max_Char_Symbol];  // Buffer to store input
    size_t len;
    FILE *input_file = stdin;  // Open stdin in read mode


    fgets(input, sizeof(input), input_file);  // Read input from stdin using fgets
    len = strlen(input);  // Remove newline character if present

    if (len > 0 && input[len - 1] == '\n')
        input[len - 1] = '\0';

    // Process the input (e.g., perform some operations)
    sprintf_s(processedOutput, sizeof(processedOutput), "Processed: %s", input);

    // Print the output to stdout using fputs
    fputs(processedOutput, stdout);
    fputs("\n", stdout);
}
//------------------------------------------------------------------------------------------------------------------
string AHacker_Rank_Tasks::ltrim(const string &str)
{
    string s(str);

    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int c)
            {
                return !std::isspace(c);
            })
    );

    return s;
}
//------------------------------------------------------------------------------------------------------------------
string AHacker_Rank_Tasks::rtrim(const string &str)
{
    string s(str);

    s.erase(std::find_if(s.rbegin(), s.rend(), [](int c)
        { 
            return !std::isspace(c);
        } ).base(), s.end());

    return s;
}
//------------------------------------------------------------------------------------------------------------------
string AHacker_Rank_Tasks::Convert_To_Word(int n)
{
    if (n >= 1 && n <= 9) {
        return AsConfig::Words[n - 1];
    }

    return "";
}
//------------------------------------------------------------------------------------------------------------------
