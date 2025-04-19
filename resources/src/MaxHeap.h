//
// Created by alexd on 4/10/2025.
//

#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <queue>
#include <vector>
#include <utility>
#include "City.h"
using namespace std;

class MaxHeap {
    vector<pair<int, City>> heap;
    void heapify_up(int position);
    void heapify_down(int position);

public:
    MaxHeap();
    MaxHeap(vector<City>& cities);
};



#endif //MAXHEAP_H
