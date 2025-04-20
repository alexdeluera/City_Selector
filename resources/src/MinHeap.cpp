#include "MinHeap.h"
#include <iostream>

MinHeap::MinHeap(vector<City>& cities) {
    this->minHeap = {};

    for (int i = 0; i < cities.size(); i++) {
        if (cities[i].get_city_match() > 1) {
            pair<int, City> this_city(cities[i].get_pop(), cities[i]);
            if(minHeap.size() == maxSize && this_city.first < minHeap[0].first ){
                continue;
            }
            minHeap.push_back(this_city);
            heapify_up(minHeap.size()-1);

            if(minHeap.size() > maxSize) extract_min();
        }
    }
}

void MinHeap::swap(int child, int parent) {
    auto temp = minHeap[child];
    minHeap[child] = minHeap[parent];
    minHeap[parent] = temp;
}

void MinHeap::heapify_up(int index) {
    int parent = (index-1) /2;
    while(index > 0 && minHeap[parent].first > minHeap[index].first){
        swap( index, parent);
        index = parent;
        parent = (index -1)/2;
    }
}

void MinHeap::heapify_down(int index, int size) {
    while(true){
        int smallest = index;
        int left = (smallest * 2) + 1;
        int right = (smallest * 2) + 2;

        if(left < size && minHeap[left].first < minHeap[smallest].first) smallest = left;
        if(right < size && minHeap[right].first < minHeap[smallest].first) smallest = right;
        if(smallest == index) break;

        swap(smallest,index);
        index = smallest;
    }
}

City MinHeap::extract_min() {
    auto extractedCity = minHeap[0].second;
    minHeap[0] = minHeap[minHeap.size()-1];
    minHeap.pop_back();
    heapify_down(0, minHeap.size());

    return extractedCity;
}

void MinHeap::top_5_cities() {
    cout << "minheap size " <<minHeap.size() <<endl;

    string cityName[5];
    for (int i=4; i>=0; i--) {
        cityName[i] = extract_min().get_city_name();

    }
    int i = 0;
    for(const auto& el : cityName){
        cout<<i+1<<". "<< el << endl;
        i++;
    }
}