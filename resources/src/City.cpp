#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "City.h"

using namespace std;

City::City(string city_name, string country, int population, double latitude) {
    //constructor for the class City
    this->city_name = city_name;
    this->country = country;
    this->population = population;
    this->latitude = latitude;
}

void City::match_city(string& country_pref, int pop_pref, int lat_pref) {
    if (country_pref == country) {
        city_match+=1;
    }

    //values for the pop bin cutoffs were gathered from the data set by sorting the population values into equally
    //sized bins, thus the city size is relative to the other cities in the data set
    if (pop_pref == 1 && population<=11073) {
        city_match+=0.25;
    }
    else if (pop_pref == 2 && 11073<population && population<=16421) {
        city_match+=0.25;
    }
    else if (pop_pref == 3 && 16421<population && population<=27115) {
        city_match+=0.25;
    }
    else if (pop_pref == 4 && 27115<population && population<=60212) {
        city_match+=0.25;
    }
    else if (pop_pref == 5 && 60212<population && population<=3.7732e+07) {
        city_match+=0.25;
    }

    //formula for adding in the latitude (weather) match
    if (lat_pref == 1 && latitude<=15) {
        city_match+=0.25;
    }
    else if (lat_pref == 2 && 15<latitude && latitude<=30) {
        city_match+=0.25;
    }
    else if (lat_pref == 3 && 30<latitude && latitude<=45) {
        city_match+=0.25;
    }
    else if (lat_pref == 4 && 45<latitude && latitude<=60) {
        city_match+=0.25;
    }
    else if (lat_pref == 5 && 60<latitude && latitude<=75) {
        city_match+=0.25;
    }
}

float City::get_city_match() {
    return this->city_match;
}

double City::get_pop() {
    return this->population;
}

double City::get_latitude() {
    return this->latitude;
}

string City::get_city_name() {
    return this->city_name;
}

string City::get_country() {
    return this->country;
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

        int population=0;
        double latitude = 0.0;

        city_name = city_name.substr(1, city_name.size()-2);
        country = country.substr(1, country.size()-2);

        //population string saved to City object after: quotes trimmed, converted to int
        stringstream populationDouble(string_population);
        string_population = string_population.substr(1,string_population.length()-2);
        if (string_population=="") {
            population = 0;
        }
        else {
            population = stoi(string_population);
        }

        //a similar fix to the latitude values to clean the strings
        stringstream latitudeDouble(latitude_str);
        latitude_str = latitude_str.substr(1,latitude_str.length()-2);
        latitude = abs(stod(latitude_str));

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

        int population=0;
        double latitude = 0.0;

        city_name = city_name.substr(1, city_name.size()-2);
        country = country.substr(1, country.size()-2);

        //population string saved to City object after: quotes trimmed, converted to int
        stringstream populationDouble(string_population);
        string_population = string_population.substr(1,string_population.length()-2);
        if (string_population=="") {
            population = 0;
        }
        else {
            population = stoi(string_population);
        }

        //a similar fix to the latitude values to clean the strings
        stringstream latitudeDouble(latitude_str);
        latitude_str = latitude_str.substr(1,latitude_str.length()-2);
        latitude = abs(stod(latitude_str));

        City this_city(city_name, country, population, latitude);

        this_city.match_city(country_pref, pop_pref, lat_pref);

        city_info.emplace_back(this_city);

    }
    return city_info;

}


