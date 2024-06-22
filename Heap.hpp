#include <vector>
#include "Iterator.hpp"
#pragma once

using namespace std;

template<typename T>
class MinHeap{

    vector<T> _array;

    void minHeapify(vector<T>& heapArray, int i){
        int lowest;
        int l = 2*i;
        int r = 2*i+1;

        if (l < _array.size() && (heapArray[l] < heapArray[i])) {
            lowest = l;
        }

        else {
            lowest = i;
        }

        if (r < _array.size() && heapArray[r] < heapArray[lowest]) {
            lowest = r;
        }

        if (lowest != i) {
            T temp = heapArray[i];
            heapArray[i] = heapArray[lowest];
            heapArray[lowest] = temp;
            minHeapify(heapArray, lowest);
        }
    }

    void buildMinHeap(){
        for(int i=_array.size()/2;i >= 0 ;i--){
            minHeapify(_array,i);
        }
    }

public:
    MinHeap()= default;

    MinHeap(iterator_bfs<T> begin,iterator_bfs<T> end){
        for (auto node = begin; node != end; ++node)
        {
            _array.push_back(node->get_value());
        }

        buildMinHeap();
    }

    vector<T>& getHeap(){
        return _array;
    }
};
