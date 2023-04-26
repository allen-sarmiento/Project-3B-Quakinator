#pragma once
#include <vector>
#include <string>

using namespace std;

struct Earthquake {
    int time;
    string sTime;
    double magnitude;
    double longitude;
    double latitude;

    Earthquake(string sTime, double magnitude, double longitude, double latitude) {
        this->sTime = sTime;
        this->magnitude = magnitude;
        this->longitude = longitude;
        this->latitude = latitude;
        this->time = -1;
    };

    void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    };

    /*
    static bool compareByTime(const Earthquake& a, const Earthquake& b) {
        return a.time < b.time;
    };
    */

    static  bool compareByMagnitude(const Earthquake& a, const Earthquake& b) {
        return a.magnitude < b.magnitude;
    };

    static bool compareByLongitude(const Earthquake& a, const Earthquake& b) {
        return a.longitude < b.longitude;
    };

    static bool compareByLatitude(const Earthquake& a, const Earthquake& b) {
        return a.latitude < b.latitude;
    };

    string to_string() {
        return "Time(" + this->sTime + "), Lat(" + std::to_string(this->latitude)  + "), Lon(" + std::to_string(this->longitude) + "), Mag(" + std::to_string(this->magnitude) + ")";
    };
};