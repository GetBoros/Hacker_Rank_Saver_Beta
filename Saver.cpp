#include "Saver.h"

// AsSaver | Saver beta 0.2.1
const string AsSaver::Warning = " - is wrong input, need enter 1-5: or \"exit\" if you need Exit\n ";
const string AsSaver::End_Watch = "|End|";
const string AsSaver::Pause_Anime = "|Pause|";
const string AsSaver::Saver_Version = "Welcome to Savers:\t\tbeta 0.2.1";
const string AsSaver::Titles = "\nPress 1 to Save\nPress 2 to Load\nPress 3 to Add Data\nPress 4 to Erase Data\nPress 5 to exit\n";
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
    cout << "Time last visit was be saved";
}
//-------------------------------------------------------------------------------------------------------------------------------
AsSaver::AsSaver()
: Save_Menu(ESave_Menu::Handler), Counter_List(0), Max_Array_Size(0.0), Slasher(Saver_Version)
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
    Check_If_File_Excist();

    // Tasks
    /*
    
    qwer I 23
    if i write qwer II 1
    need delete qwer I or set do end array

    Need test to find bugs and how upgrade

    Anime Ratio, Time when was be addet.

    from version 0.3.0 maybe go to GUI

    */

    while (Save_Menu != ESave_Menu::Exit)
        Choser();
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Choser()
{
    if (Save_Menu != ESave_Menu::Add_Data && Save_Menu != ESave_Menu::Delete)
        Save_Menu = Proccesing_Reguest();

    switch (Save_Menu)
    {
    case ESave_Menu::Handler:
        Choser();  // Done
        break;

    case ESave_Menu::Save:
        //Save_Menu = ESave_Menu::Handler;
        Save_To_File();  // Done
        break;

    case ESave_Menu::Load:
        Save_Menu = ESave_Menu::Handler;
        Read_Lines_From_File();  // Done
        break;

    case ESave_Menu::Add_Data:
        Add_Data_To_List_New_Beta();  // Done
        break;

    case ESave_Menu::Delete:
        Delete_Data_From_List();  // Enter string "«qwer qwer»" to delete from array
        break;

    case ESave_Menu::Exit:
        Save_To_File();  // Done
        break;

    default:
        AsConfig::Throw();
    }

    if (Save_Menu == ESave_Menu::Handler)
        cout << Titles << endl;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Add_Data_To_List_New_Beta()
{
    bool is_paused;
    bool is_end;
    int anime_series;
    string anime_title_to_array;
    string anime_title_to_delete;
    
    is_paused = false;
    is_end = false;

    anime_title_to_array = Input_Handler(is_paused, is_end, anime_series, anime_title_to_delete);

    if (anime_title_to_array == "«")
        return;

    if (anime_title_to_array != "«")
    {
        Add_To_Specifer_Lists(is_paused, is_end, anime_title_to_array, anime_series);
        if (anime_title_to_delete != "")
            Delete_Data_From_List(anime_title_to_delete);
        else
            Save_To_File();
    }
    else
        Save_Menu = ESave_Menu::Handler;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Delete_Data_From_List(const string &del_from_array)
{
    bool is_paused;
    bool is_end;
    int series;
    string to_delete_from_array;

    is_paused = false;
    is_end = false;

    if (del_from_array != "")
        to_delete_from_array = del_from_array;
    else
        to_delete_from_array = Input_Handler(is_paused, is_end, series, to_delete_from_array);

    if (to_delete_from_array != "«")
    {
        if (is_paused)
            Anime_Map_Paused.erase("|Pause|" + to_delete_from_array);
        else if (is_end)
            Anime_Map_End_Watch.erase("|End|" + to_delete_from_array);
        else
            Anime_Map.erase(to_delete_from_array);
        cout << "Delet was seccuss! \n";
        Save_To_File();
    }
    else
        Save_Menu = ESave_Menu::Handler;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Save_To_File()
{
    ofstream out_put_to_file;

    out_put_to_file.open(AsConfig::Path);  // Directory and rewrite or add to file | "C:\\Program Files\\example.txt"

    for (auto &it : Anime_Map)
        out_put_to_file<< it.first << it.second << "\n";

    for (auto &it : Anime_Map_End_Watch)
        out_put_to_file<< it.first << it.second << "\n";

    for (auto &it : Anime_Map_Paused)
        out_put_to_file<< it.first << it.second << "\n";

    cout << "Save success!\n";
    out_put_to_file.close();
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Read_Lines_From_File()
{
    int max_string_size = 0;
    ifstream fin;
    string text_from_file;
    ASlasher slasher_load("Lists");

    fin.open(AsConfig::Path);

    while(getline(fin, text_from_file) )
    {
        int int_to_arr = 0;
        string string_to_arr = "";

        Refactoring_String(text_from_file, string_to_arr, int_to_arr);

        if(string_to_arr.find(End_Watch) != string::npos)
            Anime_Map_End_Watch.emplace(string_to_arr, int_to_arr);  // Add ended watching anime 
        else 
            if(string_to_arr.find(Pause_Anime) != string::npos)
                Anime_Map_Paused.emplace(string_to_arr, int_to_arr);
            else
                Anime_Map.emplace(string_to_arr, int_to_arr);  // Add To Map List which sort by char
    }

    Print_Out_Map(Anime_Map);

    cout << "\t\t\t\t\tEnd List" << endl;
    Print_Out_Map(Anime_Map_End_Watch);

    cout << "\t\t\t\t\tPaused List" << endl;
    Print_Out_Map(Anime_Map_Paused);

    if (fin.eof() )
        cout << "Load Success!" << endl;
    else
        cout << "Load False!" << endl;

    fin.close();
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Refactoring_String(const string &text, string &to_array, int &int_to_array)
{
    string::iterator it_str;
    string temp;

    for(const char &c: text)
        if (isdigit(c) )  // if true find num from line 
            temp += c;
        else  // else add char to string
            to_array += c;

    if (temp != "")
    {
        int_to_array = stoi(temp);  // convert string to int,anime series from file

        if (to_array.size() > Max_Array_Size)
            Max_Array_Size = (double)text.size();

        it_str = remove(begin(to_array), end(to_array), '\t');
        to_array.erase(it_str, to_array.end() );
    }
}
//-------------------------------------------------------------------------------------------------------------------------------
ESave_Menu AsSaver::Proccesing_Reguest()
{
    bool input_success = false;
    int input_num = 0;
    string temp;

    AsConfig::Text_Print_To_Console("", false, "Press num: ");
    do {
        try
        {
            getline(cin, temp);  // its trash code but for example its ok
            input_num = stoi(temp);

            if (input_num > 5 || input_num <= 0)
            {
                cout << input_num << Warning;
                continue;
            }
            input_success = true;
            return (ESave_Menu)input_num;
        }
        catch (const exception &)
        {
            if (temp == "exit" || temp == "Exit")
                return ESave_Menu::Exit;
        }
    } while (!input_success);
    return ESave_Menu::Exit;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Print_Out_Map(map<string, int>& anime_map)
{
    for (auto &it : anime_map)
    {
        double slasher;
        double spaces;
        const char s = ' ';
        string add = "";
        spaces = 1.0 / 8.0;

        slasher = (Max_Array_Size - it.first.size() ) / 8;
        int result = (int)(slasher / spaces);
        for (size_t i = 0; i < result; i++)
            add += s;

        cout << ++Counter_List << " " << ".\t" << it.first << add << " Series: " << it.second << endl;
    }
    cout << AsTools::Slash_String << "\n";
    Counter_List = 0;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Check_If_File_Excist()
{
    ifstream file(AsConfig::Path);

    if (file)
    {
        cout << "File Load Succes... \n" << endl;
        Read_Lines_From_File();
        file.close();
    }
    else
    {
        cout << "File don`t find. Try to create new file..." << endl;

        ofstream newFile(AsConfig::Path);
        if (newFile.is_open()) {
            newFile.close();
            cout << "Create file was succes" << endl;
        }
        else
            cout << "Не удалось создать файл." << endl;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------
string AsSaver::Input_Handler(bool &is_paused, bool &is_end, int &anime_series, string &del_from_array)
{// new task || Save string without << >> example «Верховный Бог III» 150
    int i;
    const char space = ' ';
    const char left_mark = '«';
    const char right_mark = '»';
    const string seasons[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII" };

    bool is_need_to_find;
    bool is_already_marked;
    int counter;
    string anime_title_to_array;
    string anime_title;
    bool its_season = false;
    string anime_title_to_delete;

    is_need_to_find = true;
    is_already_marked = false;
    counter = 0;
    anime_title_to_array = left_mark;

    if (Save_Menu == ESave_Menu::Delete)
        cout << "To Delete enter name and series or \"Exit\" to Exit, \"back\" to Back in main menu.\n-";
    else
        cout << "Enter Name and Series or \"Exit\" to Exit, \"back\" to Back in main menu.\n-";

    while (is_need_to_find)
    {// Input Handle

        cin >> anime_title;

        if ("Exit" == anime_title || anime_title == "exit")
        {
            Save_Menu = ESave_Menu::Exit;
            break;
        }

        if (anime_title == "Back " || anime_title == "back")
        {
            Save_Menu = ESave_Menu::Handler;
            break;
        }

        for (i = 0; i < 8; i++)
        {
            if (seasons[i] == anime_title)
            {
                its_season = true;
                continue;
            }
        }

        if (counter == 0)
        {
            if (anime_title == "paused" || anime_title == "Paused")
            {
                is_paused = true;
                continue;
            }
            else if (anime_title == "end" || anime_title == "End")
            {
                is_end = true;
                continue;
            }
            if(anime_title[0] == left_mark)
            {
                anime_title_to_array = "";
                is_already_marked = true;
            }
        }

        try
        {
            anime_series = stoi(anime_title);
            if (!is_already_marked)
                anime_title_to_array = anime_title_to_array + right_mark;

            is_need_to_find = false;
        }
        catch (const exception &)
        {
            if (counter++ == 0)
                anime_title_to_array = anime_title_to_array + anime_title;
            else
            {
                if (its_season)
                {
                    del_from_array = anime_title_to_array + right_mark;
                    anime_title_to_array = anime_title_to_array + space + anime_title;
                    its_season = false;
                }
                else
                    anime_title_to_array = anime_title_to_array + space + anime_title;
            }
        }
    }
    return anime_title_to_array;
}
//-------------------------------------------------------------------------------------------------------------------------------
void AsSaver::Add_To_Specifer_Lists(bool &is_paused, bool &is_end, string &anime_title_to_array, int &anime_series)
{
    string temp;

    if (is_paused)
    {
        temp = Pause_Anime + anime_title_to_array;
        It_Anime_Map_Pause = Anime_Map_Paused.find(temp);

        if (It_Anime_Map_Pause != Anime_Map_Paused.end() )
        {
            Anime_Map_Paused.erase(Pause_Anime + anime_title_to_array);
            Anime_Map.emplace(anime_title_to_array, anime_series);
        }
        else
            Anime_Map_Paused.emplace(Pause_Anime + anime_title_to_array, anime_series);

    }
    else if (is_end)
    {
        Anime_Map_End_Watch.emplace(End_Watch + anime_title_to_array, anime_series);
        Anime_Map.erase(anime_title_to_array);
    }
    else
    {
        It_Anime_Map = Anime_Map.find(anime_title_to_array);  // try to find same name, if true change second key
        if (It_Anime_Map != Anime_Map.end() )
            Anime_Map[anime_title_to_array] = anime_series;
        else
            Anime_Map.emplace(anime_title_to_array, anime_series);
    }
}
//-------------------------------------------------------------------------------------------------------------------------------
