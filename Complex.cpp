#ifndef COMPLEX_H
#define COMPLEX_H

#include "Complex.h"

#endif // COMPLEX_H



// AsComplex
void AsComplex::Input(string str)
{
    int i = 0;

    A = 0;
    while(str[i] != '+')
    {
        A = A * 10 + str[i] - '0';
        i++;
    }

    while(str[i] == ' ' || str[i] == '+' || str[i] == 'i')
    {
        i++;
    }

    B = 0;
    while(i < str.length() )
    {
        B = B * 10 + str[i] - '0';
        i++;
    }
}
//------------------------------------------------------------------------------------------------------------------
AsComplex operator+(const AsComplex& complex_A, const AsComplex& complex_B)
{
    return { complex_A.A + complex_B.A, complex_A.B + complex_B.B };
}
//------------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream &out_string, const AsComplex &complex)
{
    out_string << complex.A << (complex.B > 0 ? '+' : '-') << 'i' << complex.B;

    return out_string;
}
//------------------------------------------------------------------------------------------------------------------
