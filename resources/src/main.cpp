#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "City.h"
#include "MaxHeap.h"
using namespace std;
using namespace std::chrono;
int main() {
    //getting user name
    string user_name;
    cout<<"Enter name: "<<endl;
    getline(cin, user_name);
    cout<<endl;

    //getting user input for choice of country
    string country;
    cout<<"Enter country of choice: "<<endl;
    getline(cin, country);
    cout<<endl;


    //getting user input for population preference
    int population_preference;
    cout<<"Enter population preference from a scale of 1-5: 1 being least populous and 5 being most populous: "<<endl;
    cin>>population_preference;
    cout<<endl;

    //getting user input for weather preference
    int weather_preference;
    cout<<"Enter weather preference from scale of 1-5: 1 being coldest and 5 being warmest: "<<endl;
    cin>>weather_preference;
    cout<<endl;

    vector<City> cities = City::getInfo("../../../worldcities.csv", country, population_preference, weather_preference);

    //vector<City> cities = City::getInfo("../../../worldcities.csv");

    // cout<<endl << cities[0].get_latitude()<<endl;
    // cout<<cities[0].get_city_name()<<endl;
    // cout<<cities[0].get_pop()<<endl;
    // cout<<cities[0].get_city_match()<<endl;
    //
    // int full_match=0;
    // int half_match=0;
    // int quarter_match=0;
    // int japan_match=0;
    // for (auto& each:cities) {
    //     if (each.get_country() == "Japan") {
    //         japan_match++;
    //     }
    //     if (each.get_city_match()==1.5) {
    //         full_match++;
    //     }
    //     else if (each.get_city_match()==0.5) {
    //         half_match++;
    //     }
    //     else if (each.get_city_match()==0.25) {
    //         quarter_match++;
    //     }
    // }
    // cout<<full_match<<endl;
    // cout<<half_match<<endl;
    // cout<<quarter_match<<endl;
    // cout<<japan_match<<endl;
    cout<<"Here are your suggested cities "<<user_name<<": "<<endl;
    auto start_timer_maxHeap = high_resolution_clock::now();

    MaxHeap maxheap(cities);
    maxheap.top_5_cities();
    auto end_timer_maxHeap = high_resolution_clock::now();

    auto maxHeap_runtime = duration_cast<duration<double, milli>>(end_timer_maxHeap - start_timer_maxHeap);
    double maxHeap_run = static_cast<double> (maxHeap_runtime.count());

    cout<<"MaxHeap execution time: "<< fixed<<setprecision(3)<<maxHeap_run<< " milliseconds"<<endl;
    // City first = maxheap.extract_max();
    // City second = maxheap.extract_max();
    //
    // cout<<"City Name: "<<first.get_city_name()<<endl;
    // cout<<"Country: "<<first.get_city_match()<<endl;
    // cout<<"Population: "<<first.get_pop()<<endl;
    //
    // cout<<"City Name: "<<second.get_city_name()<<endl;
    // cout<<"Country: "<<second.get_city_match()<<endl;
    // cout<<"Population: "<<second.get_pop()<<endl;

    return 0;
}

