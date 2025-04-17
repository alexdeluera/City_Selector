#include <iostream>
#include <vector>
#include "City.h"
using namespace std;
int main() {
    vector<City> cities = City::getInfo("worldcities.csv");
    //getting user input for choice of country
    string country;
    cout<<"Enter country of choice"<<endl;
    getline(cin, country);

    //getting user input for choice of city
    string city_name;
    if(!country.empty()) {
        cout<<"Enter preferable city in chosen country"<<endl;
        getline(cin, city_name);
    }

    //getting user input for population preference
    int population_preference;
    cout<<"Enter population preference from a scale of 1-5: 1 being least populous and 5 being most populous"<<endl;
    cin>>population_preference;

    //getting user input for weather preference
    int weather_preference;
    cout<<"Enter weather preference from scale of 1-5: 1 being coldest and 5 being warmest"<<endl;
    cin>>weather_preference;



    return 0;
}

