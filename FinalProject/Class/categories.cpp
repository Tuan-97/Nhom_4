#include "categories.h"
#include <iostream>
#include <fstream>
#include <QFile>

Categories::Categories()
{

}
Categories::Categories(int id, string name, string description){
    this->Category_ID = id;
    this->Category_Name = name;
    this->Category_Description = description;
}
/*
string Categories::ToString(){
    string temp;
    temp += "{";
    temp += to_string(Category_ID) + ", ";
    temp += Category_Name + ", ";
    temp += Category_Description +", ";
    temp += "}";
    return temp;
}

json Categories::ToJson(){
    json temp;
    temp["CategoryID"] = Category_ID;
    temp["CategoryName"] = Category_Name;
    temp["Description"] = Category_Description;
    return temp;
}
*/

string Categories::Get_Name(){
    return this->Category_Name;
}

void Categories::Set(int id, string name, string description){
    Category_ID = id;
    Category_Name = name;
    Category_Description = description;
}

vector <Categories> GetDataBase(){
    vector <Categories> temp;
    /*Categories data;
    int id;
    string name, description;
    id = 0;
    name = "";
    description = "";
    QFile infile("Categories.txt");
    infile.open(QIODevice::ReadWrite);

    if (infile.isOpen()) {
        while(infile >> id >> name >> description){
            data.Set(id, name, description);
            temp.push_back(data);
        }
        infile.close();
    }*/
    return temp;
}
