#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "City.h"

using namespace std;

City::City(string city_name, string country, double population, double latitude) {
    //constructor for the class City
    this->city_name = city_name;
    this->country = country;
    this->population = population;
    this->latitude = latitude;
}

void City::match_city(string& country_pref, int pop_pref, int lat_pref) {
    // if (country_pref == country) {
    //     match_city+=0.5;
    // }
    // if (pop_pref == 1 && population==) {}
}

float City::get_city_match() {
    return this->city_match;
}

double City::get_pop() {
    return this->population;
}

vector<City> City::getInfo(const string& filename) {
    //function to get information from open source csv file
    vector<City> city_info;
    ifstream file(filename);
    if(!file.is_open()) {
        cerr<<"File is not open"<<endl;
    }
    string line;

    getline(file, line);
    while(getline(file, line)) {
        stringstream s(line);
        string city_name, ascii_city , latitude_str, longitude_str, country, iso2, iso3, admin_name, capital_city, string_population, id;
        getline(s, city_name, ',');
        getline(s, ascii_city, ',' );
        getline(s, latitude_str, ',');
        getline(s, longitude_str, ',');
        getline(s, country, ',');
        getline(s, iso2, ',');
        getline(s, iso3, ',');
        getline(s, admin_name, ',');
        getline(s, capital_city, ',');
        getline(s, string_population, ',');
        getline(s, id, ',');

        if(city_name.empty() || country.empty()|| latitude_str.empty()) {
            continue;
        }

        double population, latitude = 0.0;

        stringstream populationDouble(string_population);
        cout<<"City Name:"<<city_name<<endl;
        //cout<<"Population, from inside object initializer (string): "<<string_population<<endl;
        string_population = string_population.substr(1,string_population.length()-2);
        population = stod(string_population);
        cout<<"Population, from inside object initializer: "<<population<<endl;
        //populationDouble>>population;

        stringstream latitudeDouble(latitude_str);
        latitudeDouble>>latitude;

        //city_info.match_city(country_pref, pop_pref, lat_pref);

        city_info.emplace_back(city_name, country, population, latitude);

    }
    return city_info;

}

vector<City> City::getInfo(const string& filename, string& country_pref, int pop_pref, int lat_pref) {
    //function to get information from open source csv file
    vector<City> city_info;
    ifstream file(filename);
    if(!file.is_open()) {
        cerr<<"File is not open"<<endl;
    }
    string line;

    getline(file, line);
    while(getline(file, line)) {
        stringstream s(line);
        string city_name, ascii_city , latitude_str, longitude_str, country, iso2, iso3, admin_name, capital_city, string_population, id;
        getline(s, city_name, ',');
        getline(s, ascii_city, ',' );
        getline(s, latitude_str, ',');
        getline(s, longitude_str, ',');
        getline(s, country, ',');
        getline(s, iso2, ',');
        getline(s, iso3, ',');
        getline(s, admin_name, ',');
        getline(s, capital_city, ',');
        getline(s, string_population, ',');
        getline(s, id, ',');

        if(city_name.empty() || country.empty()|| latitude_str.empty()) {
            continue;
        }

        double population, latitude = 0.0;

        stringstream populationDouble(string_population);
        populationDouble>>population;

        stringstream latitudeDouble(latitude_str);
        latitudeDouble>>latitude;

        //city_info.match_city(country_pref, pop_pref, lat_pref);

        city_info.emplace_back(city_name, country, population, latitude);

    }
    return city_info;

}


