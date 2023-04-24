#pragma once
#include <vector>
#include <string>
#include <iostream>

struct Earthquake {
    int  time;
    double magnitude;
    double longitude;
    double latitude;

    void swap(int *a, int *b);
    bool compareByTime(const Earthquake& a, const Earthquake& b);
    bool compareByMagnitude(const Earthquake& a, const Earthquake& b);
    bool compareByLongitude(const Earthquake& a, const Earthquake& b);
    bool compareByLatitude(const Earthquake& a, const Earthquake& b);
};