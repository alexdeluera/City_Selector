#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class City{
private:
    string city_name;
    string country;
    double population;
    double latitude;
    int id_num;

public:
    City(string city_name, string country, double population, double latitude, int id_num);
    vector <City> getInfo(const string& filename);
};