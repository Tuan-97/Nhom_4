#include "date.h"
/*
 *  Purpose: Create method to convert Time format from string "DD/MM/YYYY" into integer YYYYMMDD
 *              and the other way.
 *  Author: Ha Xuan Tuan
 */


/*
 *  Covert a string Time format has format "DD/MM/YYYY" into a Time format integer YYYYMMDD
 */
int convertdate(std::string time){
    int year, month, day;
    if(std::sscanf(time.c_str(), "%d/%d/%d", &day, &month, &year)){
        /* Wrong Date Input
         * Date Input is like 13/11/1993
         */
        return 0;
    }
    else{
        return 10000 * year + 100 * month + day;
    }
}

/*
 * Covert Time format integer YYYYMMDD into a string has format "DD/MM/YYYY"
 */
std::string converdate(int time){
    std::string year, month, day;
    year = std::to_string(time / 10000);
    month = std::to_string((time - (time / 10000) * 10000) / 100);
    day = std::to_string(time % 100);
    return (day+"/"+month+"/"+year);
}
