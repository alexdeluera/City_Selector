#include <iostream>
#include <vector>
#include <algorithm>
#include "City.h"
using namespace std;
int main() {

    //getting user input for choice of country
    string country;
    cout<<"Enter country of choice"<<endl;
    getline(cin, country);

    //getting user input for choice of city
    // string city_name;
    // if(!country.empty()) {
    //     cout<<"Enter preferable city in chosen country"<<endl;
    //     getline(cin, city_name);
    // }

    //getting user input for population preference
    int population_preference;
    cout<<"Enter population preference from a scale of 1-5: 1 being least populous and 5 being most populous"<<endl;
    cin>>population_preference;

    //getting user input for weather preference
    int weather_preference;
    cout<<"Enter weather preference from scale of 1-5: 1 being coldest and 5 being warmest"<<endl;
    cin>>weather_preference;

    vector<City> cities = City::getInfo("../../../worldcities.csv", country, population_preference, weather_preference);

    //vector<City> cities = City::getInfo("../../../worldcities.csv");

    cout<<endl << cities[0].get_latitude()<<endl;
    cout<<cities[0].get_city_name()<<endl;
    cout<<cities[0].get_pop()<<endl;
    cout<<cities[0].get_city_match()<<endl;

    int full_match=0;
    int half_match=0;
    int quarter_match=0;
    int japan_match=0;
    for (auto& each:cities) {
        if (each.get_country() == "Japan") {
            japan_match++;
        }
        if (each.get_city_match()==1.5) {
            full_match++;
        }
        else if (each.get_city_match()==0.5) {
            half_match++;
        }
        else if (each.get_city_match()==0.25) {
            quarter_match++;
        }
    }
    cout<<full_match<<endl;
    cout<<half_match<<endl;
    cout<<quarter_match<<endl;
    cout<<japan_match<<endl;

    // //quick run to get the benchmark values for the 5 population bins to be used in city match calculation
    // sort(cities.begin(), cities.end(), [](City& a, City& b) {
    //     return a.get_pop() < b.get_pop();
    // });
    // size_t n = cities.size();
    // size_t bin_size = n/5;
    //
    // double bin1_cutoff = cities[bin_size - 1].get_pop();
    // cout << "Bin 1 (smallest population) cutoff: " << bin1_cutoff << endl;
    //
    // double bin2_cutoff = cities[2 * bin_size - 1].get_pop();
    // cout << "Bin 2 cutoff: " << bin2_cutoff << endl;
    //
    // double bin3_cutoff = cities[3 * bin_size - 1].get_pop();
    // cout << "Bin 3 cutoff: " << bin3_cutoff << endl;
    //
    // double bin4_cutoff = cities[4 * bin_size - 1].get_pop();
    // cout << "Bin 4 cutoff: " << bin4_cutoff << endl;
    //
    // // Bin 5: Cutoff at the largest population
    // double bin5_cutoff = cities[n - 1].get_pop();
    // cout << "Bin 5 (largest population) cutoff: " << bin5_cutoff << endl;
    //
    // cout<<"Bin Size: "<<bin_size<<endl;

    return 0;
}

