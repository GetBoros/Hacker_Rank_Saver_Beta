#include "Saver.h"

// AsSaver | Saver beta 0.2.7
const string AsSaver::Warning = " - is wrong input, need enter 1-5: or \"exit\" if you need Exit\n ";
const string AsSaver::End_Watch = "|End|";
const string AsSaver::Pause_Anime = "|Pause|";
const string AsSaver::Saver_Version = "Welcome to Savers:\t\tbeta 0.2.7";
const string AsSaver::Titles = "\nPress 1 to Save\nPress 2 to Load\nPress 3 to Add Data\nPress 4 to Erase Data\nPress 5 to exit\n";
const char AsSaver::Space = ' ';
const char AsSaver::Left_Mark = '«';
const char AsSaver::Right_Mark = '»';
const string AsSaver::Seasons[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII" };
//-------------------------------------------------------------------------------------------------------------------------------
AsSaver::~AsSaver()
{
    // write binary Local_Time
    GetLocalTime(&ASlasher::Local_Time);  // Save last visit to Local time
    ofstream data_bin("Data.bin", ios::binary);
    if (data_bin.is_open() )
    {
        data_bin.write(reinterpret_cast<char*>(&ASlasher::Local_Time), sizeof(ASlasher::Local_Time) );
        data_bin.close();
    }
    cout << "Time last visit was be saved\n";
}
//-------------------------------------------------------------------------------------------------------------------------------
AsSaver::AsSaver()
: Save_Menu(ESave_Menu::Handler), Counter_List(0), Max_Array_Size(0.0), Temp(""), Slasher(Saver_Version)
{
    setlocale(LC_ALL, "ru");
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Init()
{
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE);  // Console Max Size

    Handler_Main_Menu();
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Handler_Main_Menu()
{
    ASlasher slasher_load(Titles);

    Check_If_File_Excist();  // if excist load all data from file

    // Tasks
    /*
    
    Need test to find bugs and how upgrade

    How fast complete : Extract_String_And_Int and Emplace_To_Specific_Array

    Anime Ratio, Time when was be addet.
    from version 0.3.0 maybe go to GUI

    */

    while (Save_Menu != ESave_Menu::Exit)
        Choser();
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Choser()
{
    if (Save_Menu != ESave_Menu::Add_Data && Save_Menu != ESave_Menu::Delete)  // Add or Erase multiply dat
        Save_Menu = Proccesing_Reguest();

    switch (Save_Menu)
    {// Handle chose action

    case ESave_Menu::Handler:
        AsConfig::Throw();  // something wrong happens
        break;

    case ESave_Menu::Save:
        Save_To_File();  // Save Arrays to Files "MyFile"
        break;

    case ESave_Menu::Load:
        Read_Lines_From_File();  // Read data from files
        break;

    case ESave_Menu::Add_Data:
        Add_Or_Erase_Data(false);  // Add data to files
        break;

    case ESave_Menu::Delete:
        Add_Or_Erase_Data(true);  // Enter string "«qwer qwer»" to delete from array
        break;

    case ESave_Menu::Exit:
        Save_To_File();  // Save data befor exit
        break;

    default:
        AsConfig::Throw();  // something wrong happens
    }

    if (Save_Menu == ESave_Menu::Handler)  // if Handle print Titles to console
        cout << Titles << endl;
}
//-------------------------------------------------------------------------------------------------------------------------------
ESave_Menu AsSaver::Proccesing_Reguest()
{
    const int min_menu_option = static_cast<int>(ESave_Menu::Handler);
    const int max_menu_option = static_cast<int>(ESave_Menu::Exit);

    bool input_success = false;
    int input_num = 0;
    string temp;

    AsConfig::Text_Print_To_Console("", false, "Press num: ");
    do {

        try
        {
            getline(cin, temp);
            input_num = stoi(temp);

            if (input_num > max_menu_option || input_num <= min_menu_option)
            {
                cout << input_num << Warning;
                continue;
            }

            input_success = true;

            return static_cast<ESave_Menu>(input_num);
        }
        catch (const exception &)
        {// Dont need to fix exception can make problem
            if (temp == "exit" || temp == "Exit")
                return ESave_Menu::Exit;
        }

    } while (!input_success);

    return ESave_Menu::Exit;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Save_To_File()
{
    ofstream out_put_to_file;

    out_put_to_file.open(AsConfig::Path);  // Directory and rewrite or add to file | "C:\\Program Files\\example.txt"

    for (auto &it : Anime_Map)
        out_put_to_file << it.first << it.second << "\n";

    for (auto &it : Anime_Map_End_Watch)
        out_put_to_file << it.first << it.second << "\n";

    for (auto &it : Anime_Map_Paused)
        out_put_to_file << it.first << it.second << "\n";

    cout << "Save success!\n";
    out_put_to_file.close();
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Add_Or_Erase_Data(const bool &is_erase)
{
    bool is_paused;
    bool is_end;
    bool is_seccuss;
    int anime_series;
    string anime_title;
    
    is_paused = false;
    is_end = false;

    anime_title = Handle_Input(is_paused, is_end, anime_series);  // Handle user Input to add or erase data from arrays

    if (true)  // !!! maybe new functionality
    {
        Erase_Prev_Season(anime_title);  // if we add next seasons anime, delete previus
    }
    
    if (anime_title == "«")  // if input exit or back we return from func
        return;

    if (is_erase)
    {// delete from list after handle input

        if (is_paused)
            is_seccuss = Anime_Map_Paused.erase("|Pause|" + anime_title);
        else if (is_end)
            is_seccuss = Anime_Map_End_Watch.erase("|End|" + anime_title);
        else
            is_seccuss = Anime_Map.erase(anime_title);
        
        if (is_seccuss)
            cout << "Delet was seccuss! \n";
        else
            cout << "Delet was Failed! \n";
    }
    else
    {// add to list after handle input

        if (anime_title != "«")
            Add_To_Specific_List(is_paused, is_end, anime_title, anime_series);  // add to array after handle input
        else
            Save_Menu = ESave_Menu::Handler;
    }

    Save_To_File();
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Read_Lines_From_File(const bool is_need_to_print)
{
    int int_to_arr;
    string string_to_arr;
    string text_from_file;
    ifstream fin;
    ASlasher slasher_load("Lists");

    fin.open(AsConfig::Path);

    while(getline(fin, text_from_file) )  // set line to text_from_file
    {
        int_to_arr = 0;
        string_to_arr = "";

        Extract_String_And_Int(text_from_file, string_to_arr, int_to_arr);
        Emplace_To_Specific_Array(string_to_arr, int_to_arr);
    }

    if (is_need_to_print)
    {
        Print_Out_Map(Anime_Map);
        cout << "\t\t\t\t\tEnd List" << endl;

        Print_Out_Map(Anime_Map_End_Watch);
        cout << "\t\t\t\t\tPaused List" << endl;

        Print_Out_Map(Anime_Map_Paused);
    }

    if (fin.eof() )
        cout << "Load Success!" << endl;
    else
        cout << "Load False!" << endl;

    fin.close();
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Extract_String_And_Int(const string &text, string &to_array, int &int_to_array)
{
    to_array = text;  // use to_array_like_temp
    size_t pos = to_array.rfind(Right_Mark);  // find mark(index) position in string from end 

    if (pos != string::npos)  // if can`t find pos don`t do
    {
        to_array = text.substr(pos + 1);  // substr before mark and + 1 with mark
        int_to_array = stoi(to_array);

        to_array = text;
        to_array.erase(pos + 1);  // erase after after mark + 1 with mark
    }

    if (to_array.size() > Max_Array_Size)  // it`s for spaces between string and integers
        Max_Array_Size = (double)text.size();

    // Temp example second
    /* 
    //string::iterator it = find(text.begin(), text.end(), Right_Mark);  // Find 
    //text.erase(it + 1, text.end() );
    //to_array = text;

    //temp.erase(0, pos + 1);
    //int_to_array = stoi(temp);  // convert string to int

    //if (to_array.size() > Max_Array_Size)
    //    Max_Array_Size = (double)text.size();

     Temp example second end 
     */

    // Temp example first
    /* 
    //for(const char &c: text)  // For optimization find from end nums 
    //    if (isdigit(c) )  // if true we find num from line 
    //        temp += c;
    //    else  // else add char to string
    //        to_array += c;  // change? copy text to array end erase last nums

    //if (temp != "")
    //{
    //    int_to_array = stoi(temp);  // convert string to int

    //    if (to_array.size() > Max_Array_Size)
    //        Max_Array_Size = (double)text.size();

    //    it_str = remove(begin(to_array), end(to_array), '\t');
    //    to_array.erase(it_str, to_array.end() );
    //}
    */
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Emplace_To_Specific_Array(const string &title, const int &series)
{
    if(title.find(End_Watch) != string::npos)
        Anime_Map_End_Watch.emplace(title, series);  // Add ended watching anime 
    else 
        if(title.find(Pause_Anime) != string::npos)
            Anime_Map_Paused.emplace(title, series);
        else
            Anime_Map.emplace(title, series);  // Add To Map List which sort by char
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Print_Out_Map(const map<string, int> &anime_map)
{
    int spaces_to_place;
    double tabs;
    double spaces;
    double str_indexes;
    double spaces_in_tab;

    const char symb = ' ';
    spaces_in_tab = 8.0;
    spaces = 1.0 / spaces_in_tab;

    for (auto &it : anime_map)
    {
        str_indexes = static_cast<double>(it.first.size() );  // how much indexes has string with + 1
        tabs = (Max_Array_Size - str_indexes) / spaces_in_tab;  // how much tabs need add
        spaces_to_place = static_cast<int>(tabs / spaces);  // how spaces need add
        string str_with_spaces(spaces_to_place, symb);  // create str with spaces

        cout << ++Counter_List << " .\t" << it.first << str_with_spaces << " Series: " << it.second << endl;  // print to consol
    }

    cout << AsTools::Slash_String << "\n";  // Show end of list
    Counter_List = 0;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Check_If_File_Excist()
{
    ifstream file(AsConfig::Path);

    if (file)
    {// if file excist

        // !!! How fast we read_from_files in ms
        cout << "File Load Succes... \n" << endl;
        Read_Lines_From_File(false);
        file.close();
    }
    else
    {// if not create new file

        cout << "File don`t find. Try to create new file..." << endl;

        ofstream newFile(AsConfig::Path);
        if (newFile.is_open() )
        {
            newFile.close();
            cout << "Create file was succes" << endl;
        }
        else
            cout << "Can`t create file" << endl;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------
string AsSaver::Handle_Input(bool &is_paused, bool &is_end, int &anime_series)
{// new task || Save string without << >> example «Верховный Бог III» 150
    bool is_need_to_find;
    bool is_already_marked;
    bool is_first_time;
    int counter;
    string anime_title_to_array;
    string anime_title;

    is_need_to_find = true;
    is_already_marked = false;
    counter = 0;
    anime_title_to_array = Left_Mark;
    is_first_time = true;

    if (Save_Menu == ESave_Menu::Delete)
        cout << "To Delete enter name and series or \"Exit\" to Exit, \"back\" to Back in main menu.\n-";
    else
        cout << "Enter Name and Series or \"Exit\" to Exit, \"back\" to Back in main menu.\n-";

    while (is_need_to_find)  // Handle Input from User
    {
        cin >> anime_title;  // wait input

        if (is_first_time)  // check only first time
        {
            if (Check_Back_Or_Exit_Input(anime_title) )
                break;

            is_first_time = false;

            if (Check_End_Or_Paused_Input(anime_title, is_paused, is_end) )  // if input "end" or "paused"
                continue;

            if(anime_title[0] == Left_Mark)  // if we have mark symb in index 0 reset adding mark and tell what it`s marked
            {
                anime_title_to_array = "";
                is_already_marked = true;
            }
        }

        try
        {
            anime_series = stoi(anime_title);  // if not int

            is_need_to_find = false;  // if false we find nums to end the cycle
            if (!is_already_marked)
                anime_title_to_array = anime_title_to_array + Right_Mark;

        }
        catch (const exception &)  // !!! Need refactoring
        {
            if (counter++ == 0)
                anime_title_to_array = anime_title_to_array + anime_title;
            else
                anime_title_to_array = anime_title_to_array + Space + anime_title;
        }

    }
    return anime_title_to_array;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Erase_Prev_Season(const string &anime_title)
{

}
//-------------------------------------------------------------------------------------------------------------------------------
bool AsSaver::Check_Back_Or_Exit_Input(const string &anime_title)
{
    if ("Exit" == anime_title || anime_title == "exit")
    {
        Save_Menu = ESave_Menu::Exit;
        return true;
    }

    if ("Back" == anime_title || anime_title == "back")
    {
        Save_Menu = ESave_Menu::Handler;
        return true;
    }

    return false;
}
//-------------------------------------------------------------------------------------------------------------------------------
bool AsSaver::Check_End_Or_Paused_Input(const string& anime_title, bool &is_paused, bool &is_end)
{

    if ("Paused" == anime_title  || anime_title == "paused")
    {
        is_paused = true;
        return true;
    }
    else if ("End" == anime_title || anime_title == "end")
    {
        is_end = true;
        return true;
    }

    return false;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Add_To_Specific_List(const bool &is_paused, const bool &is_end, const string &anime_title_to_array, const int &anime_series)
{
    string temp;

    if (is_paused)
    {
        temp = Pause_Anime + anime_title_to_array;
        It_Anime_Map_Pause = Anime_Map_Paused.find(temp);

        if (It_Anime_Map_Pause != Anime_Map_Paused.end() )
            Anime_Map_Paused.emplace(temp, anime_series);
        else
        {
            Anime_Map_Paused.emplace(Pause_Anime + anime_title_to_array, anime_series);
            Anime_Map.erase(anime_title_to_array);
            Anime_Map_End_Watch.erase(End_Watch + anime_title_to_array);
        }

    }
    else if (is_end)
    {
        Anime_Map_End_Watch.emplace(End_Watch + anime_title_to_array, anime_series);
        Anime_Map.erase(anime_title_to_array);
        Anime_Map_Paused.erase(Pause_Anime + anime_title_to_array);
    }
    else
    {
        It_Anime_Map = Anime_Map.find(anime_title_to_array);  // try to find same name, if true change second key
        It_Anime_Map_End_Watch = Anime_Map_End_Watch.find(End_Watch + anime_title_to_array);
        It_Anime_Map_Pause = Anime_Map_Paused.find(Pause_Anime + anime_title_to_array);

        if (It_Anime_Map != Anime_Map.end() )
            Anime_Map[anime_title_to_array] = anime_series;
        else
            Anime_Map.emplace(anime_title_to_array, anime_series);

        if (It_Anime_Map_End_Watch != Anime_Map_End_Watch.end() )
            Anime_Map_End_Watch.erase(End_Watch + anime_title_to_array);

        if (It_Anime_Map_Pause != Anime_Map_Paused.end() )
            Anime_Map_Paused.erase(Pause_Anime + anime_title_to_array);
    }
}
//-------------------------------------------------------------------------------------------------------------------------------
