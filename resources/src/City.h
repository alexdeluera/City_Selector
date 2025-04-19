#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class City{
private:
    string city_name;
    string country;
    int population;
    double latitude;
    float city_match = 0.0;

public:
    City(string city_name, string country, int population, double latitude);
    void match_city(string& country_pref, int pop_pref, int lat_pref);
    float get_city_match();
    double get_pop();
    string get_country();
    static vector <City> getInfo(const string& filename); //needed for viewing data to find bounds on pop and lat bins
    static vector <City> getInfo(const string& filename, string& country_pref, int pop_pref, int lat_pref);
    double get_latitude();
    string get_city_name();
};