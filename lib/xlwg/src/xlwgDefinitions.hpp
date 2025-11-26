////////////////////////////////////////////////////////////////////////////////////////////////////
//*FILE NAME:       xlwg.cpp
//*FILE DESC:       Macro definitions for xlwg library.
//*FILE VERSION:    0.70
//*FILE AUTHOR:     The Eichen Group
//*CONTRIBUTORS:    Chimaroke Okwara
//*LAST MODIFIED:   Saturday, 11 June 2022 16.12
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef GEN_DEFS
#define GEN_DEFS

#include <time.h>
#include <stdint.h>

//Variables:
    #define A alphabets[0]
    #define E alphabets[1]
    #define I alphabets[2]
    #define O alphabets[3]
    #define U alphabets[4]
    #define Y alphabets[5]

//Types:
    using uint = unsigned int;
    using ulong = unsigned long;
    using uchar = unsigned char;


//Methods:
namespace xlwg
{
  void delay(const ulong &sec);   //Delay for sec seconds
}


#endif
