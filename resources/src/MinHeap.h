#ifndef MINHEAP_H
#define MINHEAP_H
#include <queue>
#include <vector>
#include <utility>
#include "City.h"

using namespace std;

class MinHeap {
    int maxSize = 5;
    vector<pair<int, City>> minHeap;
    int top();
    void swap( int child, int parent);
    void heapify_up(int position);
    void heapify_down(int position, int size);

public:
//    MinHeap();
    MinHeap(vector<City>& cities);

    City extract_min();
    void top_5_cities();
    string top_5_str();
};



#endif //MINHEAP_H
