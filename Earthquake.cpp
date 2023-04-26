/*
#include "Earthquake.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;  

Earthquake::Earthquake(string sTime, double magnitude, double longitude, double latitude) {
    this->sTime = sTime;
    this->magnitude = magnitude;
    this->longitude = longitude;
    this->latitude = latitude;
}

void Earthquake::swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
bool Earthquake::compareByTime(const Earthquake& a, const Earthquake& b) {
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

string Earthquake::to_string() {
    return "Time(" + sTime + "), Lat(" + std::to_string(latitude)  + "), Lon(" + std::to_string(longitude) + "), Mag(" + std::to_string(magnitude) + ")";
}
*/