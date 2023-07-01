#include "String.h"

// AString
AString::~AString()
{
    delete[] Str;
}
//------------------------------------------------------------------------------------------------------------------
AString::AString()
    : Str(0), Array_Length(0)
{
}
//------------------------------------------------------------------------------------------------------------------
AString::AString(const char* str)
    : Array_Length(0)
{
    Add_To_Array(str);
}
//------------------------------------------------------------------------------------------------------------------
bool AString::operator==(const AString& other)
{
    int i;

    if (Array_Length != other.Array_Length)
        return false;

    for (i = 0; i < Array_Length; i++)
        if (Str[i] != other.Str[i])
            return false;

    return true;
}
//------------------------------------------------------------------------------------------------------------------
bool AString::operator!=(const AString& other)
{
    return !(this->operator==(other));
}
//------------------------------------------------------------------------------------------------------------------
char& AString::operator[](int index)
{


    return Str[index];
}
//------------------------------------------------------------------------------------------------------------------
AString& AString::operator=(const AString &other)
{
    if (Str != 0)
        delete[] Str;

    Add_To_Array(other.Str);

    return *this;
}
//------------------------------------------------------------------------------------------------------------------
AString AString::operator+(const AString& other)
{
    AString new_string;
    int i, j;

    new_string.Array_Length = (int)(strlen(Str) + strlen(other.Str));

    new_string.Str = new char[new_string.Array_Length + 1];
    i = 0;

    for (; i < strlen(Str); i++)
        new_string.Str[i] = Str[i];

    for (j = 0; j < strlen(other.Str) && i < new_string.Array_Length; j++, i++)
        new_string.Str[i] = other.Str[j];

    if (i <= new_string.Array_Length)
        new_string.Str[i] = '\0';

    return new_string;
}
//------------------------------------------------------------------------------------------------------------------
void AString::Add_To_Array(const char* str)
{
    int i;

    Array_Length = (int)strlen(str);
    Str = new char[Array_Length + 1];

    for (i = 0; i < Array_Length; i++)
        Str[i] = str[i];

    Str[Array_Length] = '\0';
}
//------------------------------------------------------------------------------------------------------------------
void AString::Print()
{
    cout << Str;
}
//------------------------------------------------------------------------------------------------------------------
int AString::Length()
{

    return Array_Length;
}
//------------------------------------------------------------------------------------------------------------------
