#ifndef CATEGORIES_H
#define CATEGORIES_H
#include <string>
#include <vector>
#include "libs/json.hpp"

using namespace std;
using json = nlohmann::json;

class Categories
{
private:
    int Category_ID;
    string Category_Name, Category_Description;
public:
    Categories();
    Categories(int, string, string);
    string Get_Name();
    void Set(int, string, string);
};

vector <Categories> GetDataBase();
#endif // CATEGORIES_H
