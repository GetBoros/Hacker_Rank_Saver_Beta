#include "Example_Stl.h"




// AsExample_Stl
AsExample_Stl::~AsExample_Stl()
{
}
//------------------------------------------------------------------------------------------------------------------
AsExample_Stl::AsExample_Stl()
{
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::List(bool is_assign)
{
    list<int> list_1;
    list<int>::iterator it;
    AsType_Info<list<int> > type_info(list_1);  // show info about Forward_List
    ASlasher aslasher("List Example");
    list_1 = { 1, 2, 3, 4, 5 };

    if (is_assign)
    {
        AsConfig::Text_Print_To_Console("Assign example \n");
        list_1.assign(3, 12313);  // assing 3 it and set all to 12313
        Print_List(list_1);
    }
    else
    {
        it = list_1.begin();
        list_1.push_back(20);  // push to back num 20 now 6 elements
        list_1.push_front(10);  // push to front num 10 now 7 elements

        Print_List(list_1);

        AsConfig::Text_Print_To_Console("pop_front and pop_back: \n");
        it++;  // Move iterator x1
        advance(it, 3);  // Move it++ x3

        list_1.remove(1);  // remove all curr value 5 from list
        list_1.erase(it);  // delete element what it show

        it = list_1.begin();

        list_1.insert(it, 17);  // insert on pos it;
        list_1.pop_front();  // delete first element
        list_1.pop_back();  // delete last element

        Print_List(list_1);
    }
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Forward_List()
{
    forward_list<int> f_list;
    forward_list<int>::iterator it;
    AsType_Info<forward_list<int> > type_info(f_list);  // show info about Forward_List
    ASlasher aslasher("Forward_List Example");

    f_list = { 1, 2, 3, 4, 5 };
    f_list.push_front(9);
    f_list.push_front(10);

    it = f_list.begin();  // it = 10;
    f_list.insert_after(it, 99);  // setup after 10, 99
    f_list.erase_after(it);  // erase after 10, 99

    for (auto &it: f_list)
        cout << it << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Linked_List(bool is_input, int enter_size)
{
    int i;
    int size;
    AList<int> list_1;
    AsType_Info<AList<int> > type_info(list_1);  // show info about Linked_List
    ASlasher aslasher("Linked_List Example");

    size = enter_size;
    i = 0;

    if (is_input)
        cin >> size;
    else
    {
        for (i = 0; i < size; i++)
            list_1.Push_Back(rand() % 10);

        cout << "Elements in Lists: "<< list_1.Get_List_Size() << endl << "Excecute Pop_Front: " << endl << endl;
        list_1.Pop_Front();

        for (i = 0; i < list_1.Get_List_Size(); i++)
            cout << list_1[i] << endl;

        list_1.Clear();
        cout << "Excecute Clear(): "<< endl <<  endl << "Elements in Lists: " << list_1.Get_List_Size() << endl << endl;
    }

    cout << AsTools::Slash_String << endl;

    // Debug to watch
    list_1.Push_Back(i);
    list_1.Push_Back(i);
    list_1.Push_Back(i);
    list_1.Insert(99, 3);
    list_1.Remove_At(3);
    list_1.Pop_Back();
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Array()
{
    bool result;
    array<int, 4> arr_first; 
    array<int, 4> arr_second;
    AsType_Info<array<int, 4> > type_info(arr_first);  // show info about Array

    ASlasher aslasher("Array Example");

    arr_first = {0, 1, 2, 3 };
    arr_second = {0, 1, 2, 3 };

    result = arr_first == arr_second;  // Different operator < > != else
    cout << boolalpha << result << endl;

    cout << arr_first.front() << " - First \t Last - " << arr_first.back() << endl;

    arr_first.fill(-1);  // all elements -1

    for (auto it : arr_first)
        cout << it << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Set()
{
    bool is_done;
    int i;
    int value;
    set<int> my_set;
    set<int>::iterator it;
    pair<set<int>::iterator, bool> result;
    ASlasher aslasher("Set Example");
    AsType_Info<set<int> > type_info(my_set);  // show info about my_set

    my_set = { 11, 13, 41, 12, -1 };
    it = my_set.find(11);  // find num in set, if false set to my_set.end();
    AsConfig::Text_Print_To_Console("Enter value: ");
    cin >> value;

    for (auto &it : my_set)
        cout << it << endl;

    AsConfig::Text_Print_To_Console("Show Unique nums: \n", true);
    for (i = 0; i < 20; i++)
        my_set.insert(rand()%10);  // Insert uniqe nums for 0 to 10 same don`t assign

    for (auto &it : my_set)
        cout << it << endl;

    if (my_set.find(value) != my_set.end() )  // find our value
        AsConfig::Text_Print_To_Console("Number finded \n", true);
    else
        AsConfig::Text_Print_To_Console("Number don`t finded \n", true);

    AsConfig::Text_Print_To_Console("Delete from my_set.erase(-1) \n", true);
    is_done = my_set.erase(-1);  // delete element from set
    result = my_set.insert(123);  // insert last element to set 

    for (auto &it : my_set)
        cout << it << endl;

    cout << "Erase is: " << boolalpha << is_done << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Multi_Set()
{
    multiset<int> my_multiset;
    multiset<int>::iterator it_multi_prev;
    multiset<int>::iterator it_multi_next;
    pair<multiset<int>::const_iterator, multiset<int>::const_iterator> upper_and_lower_bound;
    ASlasher aslasher("Multi_Set Example");
    AsType_Info<multiset<int> > type_info(my_multiset);  // show info about my_multiset

    my_multiset = { 0, 1, 1, 66, 12, 16, 48, 99 };

    it_multi_prev = my_multiset.lower_bound(1);  // find lower or equal then 1
    it_multi_next = my_multiset.upper_bound(1);  // find biggest then 1
    upper_and_lower_bound = my_multiset.equal_range(1);  // pair = (lower_bound | upper_bound);
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Map()
{
    map<int, string> my_map;
    map<string, int> my_second_map;
    map<int, string>::iterator it_map;
    pair<int, string> my_pair(1, "Phone");
    pair<map<int, string>::iterator, bool> succ_result;
    ASlasher aslasher("Map Example");
    AsType_Info<map<int, string> > type_info(my_map);  // show info about my_map

    // Second Examples
    my_second_map.emplace("Sasha", 2311);
    my_second_map.emplace("Ada", 1313);
    my_second_map.emplace("Devid", 3122);
    my_second_map.emplace("Boris", 231);
    my_second_map["Lara"] = 4523;  // Add Lara to map
    my_second_map.erase("Devid");
    //my_second_map.at("Vasili") = 3;  // Get exception

    AsConfig::Text_Print_To_Console("\n", true);

    for (auto &it : my_second_map)
        cout << it.first << " " << it.second << endl;

    my_second_map["Ada"] = 1599;  // Change second var
    cout <<"\n|| Example overload []:  " << my_second_map["Ada"] << endl;

    // First Examples
    my_map.insert(my_pair);  // add pair
    my_map.emplace(4, "Desktop");
    my_map.insert(make_pair(2, "Smart Phone") );
    my_map.insert(pair<int, string>(3, "Notebook") );
    my_map.emplace(5, "Planshet");
    succ_result = my_map.emplace(5, "Planshet");

    it_map = my_map.find(1);

    if (it_map != my_map.end() )
        cout << it_map->second << endl;
    else
        cout << "Element not found " << endl;

    cout << my_pair.first << my_pair.second << "\n|| Example overload []:  " << my_map[3] << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Multimap()
{
    multimap<string, int> my_multi_map;
    ASlasher aslasher("Multimap Example");
    AsType_Info< multimap<string, int> > type_info(my_multi_map);  // show info about my_multi_map

    my_multi_map.emplace("Andrey", 123);
    my_multi_map.emplace("Andrey", 1321);
    my_multi_map.emplace("Katia", 999);
    my_multi_map.emplace("Katia", 321);

    for (auto &it : my_multi_map)
        cout << it.first << it.second << endl;

}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Stack()
{
    stack<int> st;
    stack<int, list<int> > st_list;  // if change name st_list to st nothing change
    deque<int> deq;
    string str = AsTools::Slash_String;
    ASlasher aslasher("Stack Example");
    AsType_Info< stack<int> > type_info(st);  // show info about st

    st.push(1);
    st.push(42);
    st.push(7);
    st.push(2);
    st.push(4);
    st.emplace(23);

    cout << str << endl << st.top() << "\t - Curr st.top() \t Delet last element \t"<< endl;
    st.pop();  // delet last element
    cout << st.top() << "\t - Curr st.top() \t st.size() = \t" << st.size() << endl;

    deq = st._Get_container();  // set all elements from st to deq
    cout << str << "\nExample how to use degue in stack = \t"<< deq[2] << endl << str << endl;

    while (!st.empty() )  // delete all elements
    {
        cout << st.top() << "\t = The top of stack \t st.size() = \t" << st.size() << endl;
        st.pop();  // delet last element
    }
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Queue()
{
    bool is_empty;
    int que_size;
    int front, back;
    queue<int> que_1;
    queue<int> que_2;
    deque<int> deq_que;
    ASlasher aslasher("Queue Example\tPriority_Queue");
    AsType_Info< queue<int> > type_info(que_1);  // show info about que_1
    // sort from big to low | same as queue, but have func top to see first element, sort from big to low
    priority_queue<int, vector<int>, greater<int> > prior_que;

    cout << AsTools::Slash_String << "\n" << endl;
    que_1.emplace(0);  // Add element to last queue
    que_1.push(1);  // Same emplace
    que_1.emplace(2);  // Add element to last queue
    que_1.push(3);  // Same emplace
    que_2.push(3);  // Same emplace
    que_2.emplace(2);  // Add element to last queue
    que_2.push(1);  // Same emplace
    que_2.emplace(0);  // Add element to last queue
    prior_que.emplace(23);
    prior_que.emplace(15);
    prior_que.emplace(99);
    prior_que.emplace(67);
    swap(que_1, que_2);  // Swap betwen queue 

    deq_que = que_1._Get_container();
    is_empty = que_1.empty();
    que_size = (int)que_1.size();
    front =  que_1.front();  // get first element. Can change or just see but don`t delet
    back = que_1.back();  // get last element. Can change or just see but don`t delet
    cout << front << "\t front \t back \t" << back << endl;

    while (!que_1.empty() )
    {
        cout << "In Front:\t" << que_1.front() << "\tQue Size:\t " << que_1.size() << endl;
        que_1.pop();  // delet first element
    }
    while (!prior_que.empty() )
    {
        cout << "Top:\t\t" << prior_que.top() << "\t prior_que Size:\t\t " << prior_que.size() << endl;
        prior_que.pop();  // delet first element
    }
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Sort_Algoritms()
{
    vector<int> vec;
    vector<AStudent> student_vector;
    ASlasher slasher("Sort_Algoritms Example");
    AsType_Info< vector<int> > type_info(vec);  // show info about vec

    vec = { 1, 3, 2, 6, 7, 5, 4, 9, 10 };
    student_vector = {
        AStudent("Andrey", 181),
        AStudent("Masha", 170),
        AStudent("Katy", 169),
        AStudent("Lila", 169),
        AStudent("Roma", 198),
        AStudent("Ramzes", 198),
    };

    sort(student_vector.begin(), student_vector.end(), [this](const AStudent &stud_first, const AStudent &stud_sec)
        {
            if (true)  // if true sort by name | false sord by Score
                return stud_first.Get_Name() < stud_sec.Get_Name();
            else
                return stud_first.Score > stud_sec.Score;
        } );

    // Sort vec by lambda
    sort(vec.begin(), vec.end(), [this](int a, int b) { return Greater_Then_Zero_Binar(a, b); } );
    
    for (auto &it : student_vector)
        cout << "Name: " << it.Get_Name() << "\tScore " << it.Score << endl;

    for (auto &it : vec)
        cout << it << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Find_Find_If_Algoritms()
{
    vector<int> vec;
    vector<int>::iterator vec_it;
    vector<int>::iterator vec_it_if;
    vector<int>::iterator vec_it_if_not;
    vector<AStudent> student_vector;
    vector<AStudent>::iterator student_vector_it;
    ASlasher slasher("Find_Find_If_Algoritms Example");
    AsType_Info< vector<int> > type_info_1(vec);  // show info about vec
    AsType_Info< vector<AStudent> > type_info_2(student_vector);  // show info about student_vector

    vec = { 1, 3, 2, 6, 7, 5, 4, 9, 10 };
    student_vector = {
        AStudent("Andrey", 181),
        AStudent("Masha", 170),
        AStudent("Katy", 169),
        AStudent("Lila", 169),
        AStudent("Roma", 198),
        AStudent("Ramzes", 198),
    };


    student_vector_it = find_if(student_vector.begin(), student_vector.end(), [](const AStudent &student)
        {
            return student.Get_Name() == "Andrey" && student.Score == 181;
        } );
    if (student_vector_it == student_vector.end() )
        cout << " Lost  "<< endl;
    else
        cout << "\nFindet Name and Score \n"<< endl;


    vec_it = find(vec.begin(), vec.end(), 5);  // find 5 in vector
    if (vec_it == vec.end() )
        cout << " Lost  "<< endl;
    else
        cout << "\nFindet num 5 "<< endl;


    vec_it_if = find_if(vec.begin(), vec.end(), [this](int a)
        {
            return a % 2 == 0;  // if find a % 2 number return true
        });
    if (vec_it_if == vec.end() )
        cout << " Lost  "<< endl;
    else
        cout << "\nFindet with find_if use lambda\t"<< endl;


    vec_it_if_not = find_if(vec.begin(), vec.end(), [this](int a)
        {
            return a % 2 == 0;  // if find a % 2 number return true
        });
    if (vec_it_if_not == vec.end() )
        cout << " Lost  "<< endl;
    else
        cout << "\nFindet a % 2 == 0 \n"<< endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Copy_Copy_If_Algoritms()
{
    vector<AStudent> student_vector;
    vector<AStudent> student_vector_to_copy;
    ASlasher slasher("Copy_Copy_If_Algoritms Example");
    AsType_Info< vector<AStudent> > type_info_1(student_vector);  // show info about student_vector
    AsType_Info< vector<AStudent> > type_info_2(student_vector_to_copy);  // show info about student_vector_to_copy

    student_vector = {
        AStudent("Andrey", 181, 15),
        AStudent("Masha", 170, 16),
        AStudent("Katy", 169, 19),
        AStudent("Andrey", 123, 23),
        AStudent("Lila", 169, 32),
        AStudent("Roma", 198, 25),
        AStudent("Ramzes", 200, 60),
    };

    // back_inserter func what copy to another vector
    copy_if(student_vector.begin(), student_vector.end(), back_inserter(student_vector_to_copy), [](const AStudent &s)
        {// Copy to student_vector_to_copy if Get_Age() more 24

         //return s.Get_Name() == "Andrey";  // copy_if Name Andrey
         //return s.Score <= 170;  // copy_if score <= 170
         //return s.Get_Age() >= 25 && s.Score > 180;  // copy_if age >= then 25 and score > 180
            return s.Get_Age() > 24;  // copy_if age more then 24
        } );

    sort(student_vector_to_copy.begin(), student_vector_to_copy.end(), [](const AStudent &s_1, const AStudent &s_2)
        {// Sorting by Age or Name, or Else
            return s_1.Get_Age() < s_2.Get_Age();
        } );

    cout << "Size vector: \t" << student_vector_to_copy.size() << endl;

    for (auto &it : student_vector_to_copy)
        cout << "Name: \t" << it.Get_Name() << "\tScore =\t" << it.Score << "\tAge = " << it.Get_Age() << endl;

    if (false)
        copy(student_vector.begin(), student_vector.end(), back_inserter(student_vector_to_copy) );
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Remove_if_Algoritms()
{
    bool is_remove;
    string str;
    string::iterator str_it;
    vector<AStudent> student_vector;
    vector<AStudent>::iterator student_vector_it;
    vector<int> vec;
    vector<int>::iterator vec_it;
    ASlasher slasher("Remove_if_Algoritms Example");
    AsType_Info< vector<AStudent> > type_info_1(student_vector);  // show info about student_vector
    AsType_Info< vector<int> > type_info_2(vec);  // show info about vec

    is_remove = false;
    str = "Text  with few  spaces";
    vec = { 1, 3, 2, 6, 7, 5, 4, 9, 10, 9, 4, 5, 2};
    student_vector = {
        AStudent("Andrey", 181, 15),
        AStudent("Masha", 170, 16),
        AStudent("Katy", 169, 19),
        AStudent("Andrey", 123, 23),
        AStudent("Lila", 169, 25),
        AStudent("Roma", 198, 32),
        AStudent("Ramzes", 200, 53),
        AStudent("Dima", 169, 25),
        AStudent("Koly", 198, 32),
        AStudent("Oleg", 200, 53),
    };

    cout << str << endl;
    str_it = remove(str.begin(), str.end(), ' ');  // set all spaces to end and say str_it where is begining
    str.erase(str_it, str.end() );  // say from where we need erase to end array
    // str.erase(remove(str.begin(), str.end(), ' '), str.end() );  // short version
    cout << str << endl;

    if (is_remove)
    {
        // remove - move all "9" to the end of vec, vec_it return iterator to first index of "9"
        vec_it = remove(vec.begin(), vec.end(), 9);

        vec.erase(vec_it, vec.end() );  // Delete element from first "vec_it" to last "vec.end()"
    }
    else
    {
        student_vector_it = remove_if(student_vector.begin(), student_vector.end(), [](const AStudent &s_1)->bool
            {
                if (s_1.Score < 180)  // if score more then 180 delete student from array else stay
                    return false;
                else
                    return true;
            } );

        student_vector.erase(student_vector_it, student_vector.end() );

        cout << "Size vector: " << student_vector.size() << "\n" << endl;
        for (auto &it : student_vector)
            cout << "Name: " << it.Get_Name() << "\tScore: = " << it.Score << "\tAge = " << it.Get_Age() << endl;
    }
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Find_Min_Max_Element_Algoritms()
{
    bool is_vector;
    int *arr_ptr;
    vector<int> vec;
    vector<int>::iterator vec_it;
    list<int> lst;
    list<int>::iterator lst_it;
    int arr[AsConfig::Point_Array_Length] = { 1, 2, 3, 4, 5 };
    pair<vector<int>::iterator, vector<int>::iterator > vec_pair;
    ASlasher slasher("Find_Min_Max_Element_Algoritms Example");
    AsType_Info< vector<int> > type_info_1(vec);  // show info about vec
    AsType_Info< list<int> > type_info_2(lst);  // show info about student_vector

    is_vector = false;
    vec = { 1, 3, 2, 6, 7, 5, 4, 9, 10, 9, 4, 5, 2};
    lst = { 23, 3, 2, 6, 7, 5, 4, 9, 10, 9, 4, 5, 2};

    /*                                       Find Max                                                          */
    arr_ptr = max_element(arr, arr + AsConfig::Point_Array_Length);  // set max element to arr_ptr
    cout << "Max_Element: arr_ptr = " << *arr_ptr << endl;

    if (is_vector)
    {
        vec_it = max_element(vec.begin(), vec.end() );
        cout << *vec_it << endl;
    }
    else
    {
        lst_it = max_element(lst.begin(), lst.end() );
        cout << *lst_it << endl;
    }

    /*                                       Find Min                                                          */
    arr_ptr = min_element(arr, arr + AsConfig::Point_Array_Length);
    cout << "Min_Element: arr_ptr = " << *arr_ptr << endl;

    if (is_vector)
    {
        vec_it = min_element(vec.begin(), vec.end() );
        cout << *vec_it << endl;
    }
    else
    {
        lst_it = min_element(lst.begin(), lst.end() );
        cout << *lst_it << endl;
    }

    /*                                       Find Min and Max                                                    */
    vec_pair = minmax_element(vec.begin(), vec.end() );
    cout << "Min vec_pair.first = " << *vec_pair.first << "\t Max vec_pair.second = " << *vec_pair.second << endl;
    cout << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Accumulate_Algoritms()
{
    int result;
    string str_result;
    vector<int> vec;
    int arr[] = { 1, 3, 2, 6, 7, 5, 4, 9, -9, 9, 4, 5, 2 };
    int arr_m[] = { 5, 6, 7, 8 };
    ASlasher slasher("Accumulate_Algoritms Example");
    AsType_Info< vector<int> > type_info_1(vec);  // show info about vec

    vec = { 1, 3, 2, 6, 7, 5, 4, 9, -9, 9, 4, 5, 2};

    //result = accumulate(begin(arr), end(arr), 0);  // if need to sum all elements "0", don`t return iterator
    if (true)
    {
        result = accumulate(begin(arr_m), end(arr_m), 1, [](int num_1, int num_2)
            {// multiply all elements in arr
                int sum_multiply;

                sum_multiply = num_1 * num_2; 

                return sum_multiply;
            });
    }
    else
    {
        result = accumulate(begin(arr_m), end(arr_m), 0, [](int a, int b)
            {// sum all num what % 2 in arr_m, starting from third argh = 0,
                if (b % 2 == 0)  // 2,4,6
                    return a + b;
                else
                    return a;
            });
    }

    str_result = accumulate(next(begin(arr_m) ), end(arr_m), to_string(arr_m[0]), [](string str, int num)
        {// int to string with asighn "-"
            string str_sum;
            str_sum = str + " - " + to_string(num);
            return str_sum;
        });

    cout << "Result summ all element vectors = " << str_result << endl;
    cout << "Result summ all element vectors = " << result << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Mismatch_And_Equal_Algoritms()
{
    bool is_mismatch_example;
    bool is_equal;
    int arr_1[] = { 1, 3, 2, 6, 7, 5, 4, 9, -9, 9, 4, 5, 1 };
    vector<int> arr_2 = { 1, 3, 2, 6, 7, 5, 4, 9, -9, 9, 4, 5, 1 };
    pair<int *, vector<int>::iterator> pair;
    ASlasher slasher("Equal_Mismatch_Algoritms Example");
    AsType_Info< int * > type_info_1(arr_1);  // show info about arr_2
    AsType_Info< vector<int> > type_info_2(arr_2);  // show info about arr_2

    is_mismatch_example = false;
    if (is_mismatch_example)
    {
        pair = mismatch(begin(arr_1), end(arr_1), begin(arr_2), end(arr_2) );

        if (pair.first == end(arr_1) && pair.second == end(arr_2) )
            is_equal = true;
        else
            is_equal = false;
    }
    else
    {
        sort(begin(arr_1), end(arr_1) );  // sort from min to max
        sort(begin(arr_2), end(arr_2) );
        is_equal = equal(begin(arr_1), end(arr_1), begin(arr_2), end(arr_2) );  // is_arr_equal?
    }
    cout << boolalpha << "Is equal ? = "<< is_equal << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Equal_Class_Predicat_Algoritms()
{
    bool is_equal;
    APoint point;
    vector<APoint> vec_p_1;
    vector<APoint> vec_p_2;
    ASlasher slasher("Equal_Class_Predicat_Algoritms Example");
    AsType_Info< vector<APoint> > type_info_1(vec_p_1);  // show info about vec_p_1
    AsType_Info< vector<APoint> > type_info_2(vec_p_2);  // show info about vec_p_2

    vec_p_1 = {
        APoint(1, 3),
        APoint(4, 5),
        APoint(5, 7),
    };
    vec_p_2 = {
        APoint(1, 3),
        APoint(4, 5),
        APoint(5, 7),
    };

    is_equal = equal(begin(vec_p_1), end(vec_p_1), begin(vec_p_2), end(vec_p_2), [](const APoint &p_1,const APoint &p_2)
        {
            if (p_1.Get_X() == p_2.Get_X() && p_1.Get_Y() == p_2.Get_Y() )
                return true;
            else
                return false;
        });
    cout << boolalpha << is_equal << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::For_Each_Algoritms(bool is_bind)
{
    int arr_1[] = { 1, 3, 2, 6, 7, 5, 4, 9, -9, 9, 4, 5, 2 };
    ASlasher slasher("For_Each_Algoritms Example");
    AsType_Info< int * > type_info_1(arr_1);  // show info about arr_1

    // for_each element call func Show_Int
    if (is_bind)
        for_each(begin(arr_1), end(arr_1), bind(&AsExample_Stl::Show_Int, this, placeholders::_1));
    else
        for_each(begin(arr_1), end(arr_1), [](int index)
            {
                std::cout << index << std::endl;
            });
}
//------------------------------------------------------------------------------------------------------------------
void AsExample_Stl::Unique_Copy_Algoritms(bool is_unique_copy)
{
    vector<int> arr_1 = { 1, 2, 2, 2, 5, 4, 4 };
    list<int> arr_2;
    vector<int>::iterator vec_it;
    ASlasher slasher("Unique_Copy_Algoritms Example");
    AsType_Info< vector<int> > type_info_1(arr_1);  // show info about arr_1
    AsType_Info< list<int> > type_info_2(arr_2);  // show info about arr_1

    if (is_unique_copy)
        unique_copy(begin(arr_1), end(arr_1), back_inserter(arr_2) );  // Copy unique elements to arr_2
    else
    {
        vec_it = unique(begin(arr_1), end(arr_1) );  // get it or * from start not unique nums or classes

        for_each(begin(arr_1), vec_it, [this](int a)  // show unique elements
            {
                cout << a << endl;
            });

        arr_1.erase(vec_it, arr_1.end() );  // delete from vector not unique element
    }
}
//------------------------------------------------------------------------------------------------------------------
const bool AsExample_Stl::Greater_Then_Zero_Binar(const int first, const int second)
{
    return first > second;
}
//------------------------------------------------------------------------------------------------------------------
const void AsExample_Stl::Show_Int(const int a)
{
    cout << a << endl;
}
//------------------------------------------------------------------------------------------------------------------
