#pragma once

#include "Earthquake.h"

using namespace std;

struct Quakinator {

    vector<Earthquake> array;

    int partition(int low, int high, bool (*compare)(const Earthquake&, const Earthquake&)) {
        Earthquake pivot = array[low];
        int up = low;
        int down = high;

        while (up < down) {
            for (int j = up; j < high; j++) {
                if (compare(array[j], pivot)) {
                    break;
                }
                up++;
            }
            for (int j = high; j > low; j--) {
                if (!compare(array[j], pivot)) {
                    break;
                }
                down--;
            }
            if (up < down) {
                swap(array[up], array[down]);
            }
        }
        swap(array[low], array[down]);
        return down;
    }

    void quickSort(int low, int high, bool (*compare)(const Earthquake&, const Earthquake&)) {
        if (low < high) {
            int pivot = partition(low, high, compare);
            quickSort(low, pivot - 1, compare);
            quickSort(pivot + 1, high, compare);
        }
    }
};