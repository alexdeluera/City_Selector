//
// Created by alexd on 4/10/2025.
//

#include <iostream>
#include "MaxHeap.h"

MaxHeap::MaxHeap() {
    this->heap = {};
}

MaxHeap::MaxHeap(vector<City>& cities) {
    this->heap = {};

    for (int i = 0; i < cities.size(); i++) {
        if (cities[i].get_city_match() > 1) {
            pair<int, City> this_city(cities[i].get_pop(), cities[i]);
            heap.push_back(this_city);
            heapify_up(heap.size()-1);
        }
    }
}

void MaxHeap::heapify_up(int position) {
    int current = position;
    int parent = (position - 1) / 2;

    while (current > 0 && heap.at(parent).first < heap.at(current).first) {
        int temp_pop = heap.at(parent).first;
        City temp = heap.at(parent).second;

        heap.at(parent).first = heap.at(current).first;
        heap.at(parent).second = heap.at(current).second;

        heap.at(current).first = temp_pop;
        heap.at(current).second = temp;

        current = parent;
        parent = (current - 1) / 2;
    }
}

void MaxHeap::heapify_down(int position) {
    int current = position;
    int left = (current*2) + 1;
    int right = (current*2) + 2;

    while ((left<heap.size() && heap.at(current).first < heap.at(left).first) || (right<heap.size() && heap.at(current).first < heap.at(right).first)) {
        if (right<heap.size() && heap.at(left).first < heap.at(right).first) {
            int temp_pop = heap.at(right).first;
            City temp = heap.at(right).second;

            heap.at(right).first = heap.at(current).first;
            heap.at(right).second = heap.at(current).second;

            heap.at(current).first = temp_pop;
            heap.at(current).second = temp;

            current = right;
            left = (current*2)+1;
            right = (current*2)+2;
        }
        else {
            int temp_pop = heap.at(left).first;
            City temp = heap.at(left).second;

            heap.at(left).first = heap.at(current).first;
            heap.at(left).second = heap.at(current).second;

            heap.at(current).first = temp_pop;
            heap.at(current).second = temp;

            current = left;
            left = (current*2)+1;
            right = (current*2)+2;
        }
    }
}

City MaxHeap::extract_max() {
    City result = heap.at(0).second;

    // cout<<"from maxextract: "<<endl;
    // cout << heap.at(0).second.get_city_name() << endl;
    // cout<<heap.at(heap.size()-1).second.get_city_name()<<endl;

    heap.at(0).first = heap.at(heap.size()-1).first;
    heap.at(0).second = heap.at(heap.size() - 1).second;

    heap.pop_back();
    heapify_down(0);

    return result;
}

void MaxHeap::top_5_cities() {
    cout<<"Top 5 Cities: "<<endl;
    for (int i=0; i<5; i++) {
        City temp = extract_max();
        cout<<i+1<<". "<<temp.get_city_name()<<endl;
    }
}

string MaxHeap::top_5_str() {
    string result = "Top 5 Cities, from MaxHeap: \n";

    for (int i=0; i<5; i++) {
        City temp = extract_max();
        string temp_str = to_string(i+1)+". "+temp.get_city_name()+"\n";
        result+=temp_str;
    }
    return result;
}
