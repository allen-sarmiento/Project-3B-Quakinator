#pragma once

#include "Earthquake.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;  

void Earthquake::swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
bool Earthquake:: compareByTime(const Earthquake& a, const Earthquake& b) {
    return a.time < b.time;
}

bool Earthquake::compareByMagnitude(const Earthquake& a, const Earthquake& b) {
    return a.magnitude < b.magnitude;
}

bool Earthquake::compareByLongitude(const Earthquake& a, const Earthquake& b) {
    return a.longitude < b.longitude;
}

bool Earthquake::compareByLatitude(const Earthquake& a, const Earthquake& b) {
    return a.latitude < b.latitude;
}

/*
int Earthquake::partition(vector<Earthquake>& array, int low, int high, bool (*compare)(const Earthquake&, const Earthquake&)) {
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
*/

void Earthquake::quickSort(vector<Earthquake>& array, int low, int high, bool (*compare)(const Earthquake&, const Earthquake&)) {
    if (low < high) {
        int pivot = partition(array, low, high, compare);
        quickSort(array, low, pivot - 1, compare);
        quickSort(array, pivot + 1, high, compare);
    }
}
