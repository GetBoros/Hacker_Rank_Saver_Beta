#pragma once

#include "Point.h"
#include "Templates.h"

//------------------------------------------------------------------------------------------------------------------
enum class EReading_File: unsigned char
{
	Byte,
	Space,
	Line,
	Object
};
//------------------------------------------------------------------------------------------------------------------
class AExample_Lesson_Io
{
public:
	AExample_Lesson_Io();

	// .txt
	void Output_Stream(APoint &point, bool write_obj);
	void Input_Stream(EReading_File &reading_file_type);
	void Writte_Read_Objects(APoint &point);
	void FStream_Test(APoint &point);

	// .bin || binary
	void Output_Input_Binary();

private:
	void Output_Binary_Stream();
	void Input_Binary_Stream();

	void File_Read_Byte(ifstream &fin);
	void File_Read_To_Space(ifstream& fin);
	void File_Read_Line(ifstream& fin);
	void File_Read_Objects(ifstream& fin);

	string Read_From_File;
	EReading_File Reading_File_Type;
};
//------------------------------------------------------------------------------------------------------------------

// Tutorial to AExample_Lesson_Io
/*
	ofstream: Stream class to write on files
	ifstream: Stream class to read from files
	fstream:  Stream class to both read and write from/to files.

	open (filename, mode);  // filename is a string representing the name of the file 

Modes: | mode is optional parameter combination of the following flags:4
	ios::in		Open for input operations.
	ios::out	Open for output operations.
	ios::binary	Open in binary mode.
	ios::ate	Set the initial position at the end of the file. If this flag is not set, the initial position is the beginning of the file.
	ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.
	ios::trunc	If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.

All these flags can be combined using the bitwise operator OR (|) : myfile.open ("example.bin", ios::out | ios::app | ios::binary);

// ifstream::getline(); example
	char name[256], title[256];
	cin.getline(name, 256);  
	cout << name;

// get and put example seekg and seekp(seek put) 
	ifstream inputFile("input.txt");
	char ch;
	inputFile.get(ch);

	// Position inner 
	inputFile.seekg(5, ios::beg); // Move at 5-th symbol, ios::beg means at beginin of stream
	inputFile.seekg(5, ios::cur); // Move at 5-th symbol, ios::cur means at current pos of stream
	inputFile.seekg(-5, ios::end); // Move at 5-th symbol, ios::end means from end of stream

// tellg() used to find current reading position. example
	streampos begin, end;  // buffer
	begin = my_file.tellg();  // begin now show current position 

// Binary files: write(ofstream) and read(istream)
	write ( memory_block, size ); memory_size its where the data elements to be written are taken | size its how much need to read
*/