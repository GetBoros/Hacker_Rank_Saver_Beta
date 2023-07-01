#include "Example_Lesson_Io.h"

// AExample_Lesson_Io
AExample_Lesson_Io::AExample_Lesson_Io()
    : Reading_File_Type(EReading_File::Object), Read_From_File("")
{
}
//------------------------------------------------------------------------------------------------------------------
void AExample_Lesson_Io::Output_Stream(APoint &point, bool write_obj)
{
    int i;
    int enter_num;
    ofstream fout;
    ASlasher slasher("Output_Stream Example");

    fout.open(AsConfig::Path, ofstream::app);

    if (!fout.is_open() )
        cout << "File don`t open "<< endl;
    else
    {
        if (write_obj)
        {
            fout.write( (char*)&point, sizeof(APoint) );
            cout << "Object save succes!\n";
        }
        else
        {
            fout << "This is your number!:\n";

            for (i = 0; i < 5; i++)
            {
                cout << "Enter num: ";
                cin >> enter_num;

                fout << enter_num;
                fout << "\n";
            }
        }
    }
    fout.close();
}
//---------------------------------------------------------------------------------------------------
void AExample_Lesson_Io::Input_Stream(EReading_File &reading_file_type)
{
    ifstream fin;  // 
    ASlasher slasher("Input_Stream Example");

    fin.open(AsConfig::Path);

    if (fin.is_open() )
    {
        cout << "Open file succes!!" << endl;

        switch (Reading_File_Type)
        {
        case EReading_File::Byte:
            File_Read_Byte(fin);
            break;

        case EReading_File::Space:
            File_Read_To_Space(fin);
            break;

        case EReading_File::Line:
            File_Read_Line(fin);
            break;

        case EReading_File::Object:
            File_Read_Objects(fin);  // Read Objects from txt files and print to console data
            break;

        default:
            //AsConfig:Throw();
            break;
        }
    }
    else
        cout << "Can`t open file!!" << endl;

    fin.close();
}
//---------------------------------------------------------------------------------------------------
void AExample_Lesson_Io::Writte_Read_Objects(APoint &point)
{
    Output_Stream(point, true);  // Write Object to txt file 
    Input_Stream(Reading_File_Type);  // Chose type to Read Objects or what you want
    ASlasher slasher("Writte_Read_Objects Example");
}
//---------------------------------------------------------------------------------------------------
void AExample_Lesson_Io::FStream_Test(APoint &point)
{
    string write_to_file;
    string text_2;
    int value;
    fstream fs;
    APoint point_a;
    ASlasher slasher("FStream_Test Example");

    fs.open(AsConfig::Path, fstream::in | fstream::out | fstream::app);

    if (fs.is_open() )
    {
        AsConfig::AsConfig::Text_Print_To_Console("File Open \n", true, "Press button 1 to Write: Or Press button 2 to Read File: \n");
        value = 4;
        //cin >> value;

        switch (value)
        {
        case 1:  // Write two words to file in AsConfig::Path folder
            SetConsoleCP(1251);
            AsConfig::AsConfig::Text_Print_To_Console("Enter Messege: ");
            cin >> Read_From_File >> text_2;
            write_to_file = Read_From_File + " " + text_2;
            fs << write_to_file << "\n";  // Write to file
            SetConsoleCP(866);
            break;


        case 2:  // Read from file in AsConfig::Path folder, print every word with \n
            AsConfig::Text_Print_To_Console("Data from file: \n");

            while (!fs.eof() )
            {
                Read_From_File = "";
                fs >> Read_From_File;
                AsConfig::Text_Print_To_Console(Read_From_File, false, "\n");
            }
            break;


        case 3:  // write X, Y, Z to AsConfig::Path folder
            AsConfig::Text_Print_To_Console("Add object to file ");
            fs << point << "\n";
            break;


        case 4:  // Read from file if there was writted object in case 3
            while (fs >> point_a )
                cout << point_a << endl;
            AsConfig::Text_Print_To_Console(" End Read\n");
            break;


        default:
            AsConfig::Text_Print_To_Console("Value > 4 \n");
            break;
        }
    }
    else
        AsConfig::Text_Print_To_Console( "Error! \n");

    fs.close();
}
//------------------------------------------------------------------------------------------------------------------
void AExample_Lesson_Io::Output_Input_Binary()
{
    Output_Binary_Stream();  // write
    Input_Binary_Stream();  // read
}
//------------------------------------------------------------------------------------------------------------------
void AExample_Lesson_Io::Output_Binary_Stream()
{// Binary examples


    streampos streampos_size;
    map<string, int> data;

    data["key1"] = 1;
    data["key2"] = 2;
    data["key3"] = 3;

    // write to data.bin
    ofstream output_stream("data.bin", ios::binary);  // Open Data.bin in binary mode || ios::binary its a flag
    if (output_stream.is_open() )
    {
        output_stream.put('c');
        size_t size = data.size();
        output_stream.write(reinterpret_cast<const char*>(&size), sizeof(size) );

        for (const auto &pair : data)
        {
            size_t keySize = pair.first.size();
            output_stream.write(reinterpret_cast<const char*>(&keySize), sizeof(keySize) );
            output_stream.write(pair.first.c_str(), keySize);
            output_stream.write(reinterpret_cast<const char*>(&pair.second), sizeof(pair.second) );
        }

        output_stream.close();
        cout << "Map saved to data.bin" << endl;
    }
    else
    {
        cout << "Failed to open output_stream for writing." << endl;
    }
}
//------------------------------------------------------------------------------------------------------------------
void AExample_Lesson_Io::Input_Binary_Stream()
{// read from file 
    
    ifstream input_stream("data.bin", ios::binary);  // Open data.bin in binary mode for reading
    if (input_stream.is_open())
    {
        // Read the first character 'c' (if it exists)
        char firstCharacter;
        input_stream.get(firstCharacter);
        cout << "First character: " << firstCharacter << endl;

        // Read the size of the map
        size_t mapSize;
        input_stream.read(reinterpret_cast<char*>(&mapSize), sizeof(mapSize) );  // get map size from file
        cout << "Map size: " << mapSize << endl;

        // Read each key-value pair and print them
        for (size_t i = 0; i < mapSize; ++i)
        {
            // Read the key size
            size_t keySize;
            input_stream.read(reinterpret_cast<char*>(&keySize), sizeof(keySize) );

            // Read the key
            char* keyBuffer = new char[keySize + 1];  // Allocate buffer (+1 for null-terminator)
            input_stream.read(keyBuffer, keySize);
            keyBuffer[keySize] = '\0';  // Add null-terminator to create a C-string
            string key(keyBuffer);  // Convert C-string to string
            delete[] keyBuffer;  // Clean up buffer

            // Read the value
            int value;
            input_stream.read(reinterpret_cast<char*>(&value), sizeof(value) );

            // Print the key-value pair
            cout << "Key: " << key << ", Value: " << value << endl;
        }

        input_stream.close();
        cout << "Map loaded from data.bin" << endl;
    }
    else
    {
        cout << "Failed to open input_stream for reading." << endl;
    }

    //char *memblock;
    // read from file with help dynamic array
    //ifstream input_stream ("data.bin", ios::in|ios::binary|ios::ate);  // ate set get pointer to the end file
    //if (input_stream.is_open())
    //{
    //    streampos_size = input_stream.tellg();  // with ate help we get size of file and set to streampos_size
    //    memblock = new char [streampos_size];  // ask to get dynamic memory
    //    input_stream.seekg (0, ios::beg);  // now we need to set the get position to the beginning
    //    input_stream.read (memblock, streampos_size);  // read array
    //    input_stream.close();
    //    cout << "the entire input_stream content is in memory";
    //    delete[] memblock;
    //}
    //else cout << "Unable to open input_stream";
}
//------------------------------------------------------------------------------------------------------------------
void AExample_Lesson_Io::File_Read_Byte(ifstream &fin)
{// Byte by byte
    char ch;

    while (fin.get(ch) )  // Learn for a byte
        cout << ch;
}
//------------------------------------------------------------------------------------------------------------------
void AExample_Lesson_Io::File_Read_To_Space(ifstream &fin)
{
    while (!fin.eof() )
    {//!fin.eof()  // if_not_end_of_file we continue

        fin >> Read_From_File;  // from fin >> Read_From_File
        cout << Read_From_File << endl;
        Read_From_File = "";  // With out can double last str
    }
}
//------------------------------------------------------------------------------------------------------------------
void AExample_Lesson_Io::File_Read_Line(ifstream &fin)
{
    while  (getline(fin, Read_From_File) )
        cout << Read_From_File << endl;
    if (fin.eof() )
        cout << "True: End File" << endl;
    else
        cout << "False" << endl;
}
//------------------------------------------------------------------------------------------------------------------
void AExample_Lesson_Io::File_Read_Objects(ifstream &fin)
{
    APoint point_to_save;

    while (fin.read((char*)&point_to_save, sizeof(APoint) ) )
        point_to_save.Print();
}
//------------------------------------------------------------------------------------------------------------------
