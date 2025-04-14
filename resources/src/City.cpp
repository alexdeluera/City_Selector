#include <fstream>
#include <sstream>
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
        populationDouble>>population;

        stringstream latitudeDouble(latitude_str);
        latitudeDouble>>latitude;

        city_info.emplace_back(city_name, country, population, latitude);

    }
    return city_info;

}


