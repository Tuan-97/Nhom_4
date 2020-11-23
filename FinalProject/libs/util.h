#ifndef _Util_h
#define _Util_h
#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
class Util{
public:
    tm string2time(string str);
    string time2string(tm tm1);
    int compare(tm tm1, tm tm2);
    bool isEqual(tm tm1, tm tm2);
};
#endif