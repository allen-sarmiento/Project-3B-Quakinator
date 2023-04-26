#pragma once
#include <vector>
#include <string>

#include "string.h"

using namespace std;

struct Earthquake {
    int time;
    string sTime;
    double magnitude;
    double longitude;
    double latitude;

    Earthquake(string sTime = "", double magnitude = 0.0, double longitude = 0.0, double latitude = 0.0) {
        this->sTime = sTime;
        this->magnitude = magnitude;
        this->longitude = longitude;
        this->latitude = latitude;
        this->time = -1;
    };

    /*
    static bool compareByTime(const Earthquake& a, const Earthquake& b) {
        return a.time < b.time;
    };
    */

    

    string toString() {
        return "Time(" + this->sTime + "), Lat(" + std::to_string(this->latitude)  + "), Lon(" + std::to_string(this->longitude) + "), Mag(" + std::to_string(this->magnitude) + ")";
    };
};