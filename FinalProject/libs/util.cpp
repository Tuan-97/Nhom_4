#include "util.h"

tm Util::string2time(string str){
    const char* charstar = str.c_str();
    int tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec;
    tm tm1 = {0};
	sscanf(charstar,"%4d-%2d-%2d",&tm1.tm_year,&tm1.tm_mon,&tm1.tm_mday);
    return tm1;
}
string Util::time2string(tm tm1){
    char buffer[80];
    char b_mon[5];
    if (tm1.tm_mon < 10){
        sprintf(b_mon,"0%d", tm1.tm_mon);
    }
    else{
        sprintf(b_mon,"%d", tm1.tm_mon);
    }
    char b_day[5];
    if (tm1.tm_mday < 10){
        sprintf(b_day,"0%d", tm1.tm_mday);
    }
    else{
        sprintf(b_day,"%d", tm1.tm_mday);
    }
    sprintf(buffer, "%4d-%s-%s",tm1.tm_year,b_mon,b_day);
    string s(buffer);
    return s;
}
int Util::compare(tm tm1, tm tm2){
    if (tm1.tm_year > tm2.tm_year) return 1;
    else if (tm1.tm_year < tm2.tm_year) return -1;
    else 
    if (tm1.tm_mon > tm2.tm_mon) return 1;
    else if (tm1.tm_mon < tm2.tm_mon) return -1; 
    else
    if (tm1.tm_mday > tm2.tm_mday) return 1;
    else if (tm1.tm_mday < tm2.tm_mday) return -1;  
    else return 0;
}
bool Util::isEqual(tm tm1, tm tm2){
    if (tm1.tm_year != tm2.tm_year) return false;
    if (tm1.tm_mon != tm2.tm_mon) return false;
    if (tm1.tm_mday != tm2.tm_mday) return false;
    return true;
}