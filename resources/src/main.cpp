#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "City.h"
#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;
using namespace std::chrono;

int main() {

    //getting user input for choice of country
    string country;
    cout<<"Enter country of choice: "<<endl;
    getline(cin, country);

    //getting user input for population preference
    int population_preference;
    cout<<"Enter population preference from a scale of 1-5: 1 being least populous and 5 being most populous"<<endl;
    cin>>population_preference;

    //getting user input for weather preference
    int weather_preference;
    cout<<"Enter weather preference from scale of 1-5: 1 being coldest and 5 being warmest"<<endl;
    cin>>weather_preference;

    vector<City> cities = City::getInfo("../worldcities.csv", country, population_preference, weather_preference);

    cout<<"---------------------MaxHeap Implementation results------------------------"<<": "<<endl;
    auto start_timer_maxHeap = high_resolution_clock::now();

    MaxHeap maxheap(cities);
    maxheap.top_5_cities();
    auto end_timer_maxHeap = high_resolution_clock::now();

    auto maxHeap_runtime = duration_cast<duration<double, milli>>(end_timer_maxHeap - start_timer_maxHeap);
    double maxHeap_run = maxHeap_runtime.count();

    cout<<"MaxHeap execution time: "<< fixed<<setprecision(3)<<maxHeap_run<< " milliseconds"<<endl;

    cout<<endl<<"---------------------MinHeap Implementation results------------------------"<<": "<<endl;
    auto start_timer_minHeap = high_resolution_clock::now();
    MinHeap minHeap(cities);
    minHeap.top_5_cities();
    auto end_timer_minHeap = high_resolution_clock::now();

    auto minHeap_runtime = duration_cast<duration<double, milli>>(end_timer_minHeap - start_timer_minHeap);
    double minHeap_run = minHeap_runtime.count();

    cout<<"MinHeap execution time: "<< fixed<<setprecision(3)<<minHeap_run<< " milliseconds"<<endl <<endl;

    return 0;
}