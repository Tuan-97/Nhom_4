/*
 *  Purpose: Create method to convert Time format from string "DD/MM/YYYY" into integer YYYYMMDD
 *              and the other way.
 *  Author: Ha Xuan Tuan
 */
#include "iostream"
#include "fstream"
#include "date.h"
#include <map>

using namespace std;

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
std::string convertime(int time){
    std::string year, month, day;
    year = std::to_string(time / 10000);
    month = std::to_string((time - (time / 10000) * 10000) / 100);
    day = std::to_string(time % 100);
    return (day+"/"+month+"/"+year);
}

int StoreData(string from, string to){
    try{
        ifstream in(from);
        in.seekg(0, ios::end);
        size_t len = in.tellg();
        unsigned char *oData = new unsigned char[len];
        in.read((char*)(&oData[0]), len);
        in.close();

        ofstream out(to);
        out.write((char *)oData, len);
        out.close();

        delete[] oData;
        return 0;
    }
    catch(...){
        return 1;
    }
}

