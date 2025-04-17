//
// Created by alexd on 4/10/2025.
//

#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <queue>
#include "City.h"
using namespace std;

class MaxHeap {
    vector<pair<int, int>> heap;
    void calc_match(vector<City>& cities);
    void heapify();

public:
    MaxHeap();
    MaxHeap(vector<City>& cities);
};



#endif //MAXHEAP_H
