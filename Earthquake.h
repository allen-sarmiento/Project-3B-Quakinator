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

    ~Earthquake() {

    }

    Earthquake& operator=(const Earthquake& eq) {
        this->sTime = eq.sTime;
        this->magnitude = eq.magnitude;
        this->longitude = eq.longitude;
        this->latitude = eq.latitude;
        return *this;
    }

    /*
    static bool compareByTime(const Earthquake& a, const Earthquake& b) {
        return a.time < b.time;
    };
    */

    static  bool compareByMagnitude(Earthquake* a, Earthquake* b) {
        return a->magnitude < b->magnitude;
    };

    static bool compareByLongitude(Earthquake* a, Earthquake* b) {
        return a->longitude < b->longitude;
    };

    static bool compareByLatitude(Earthquake* a, Earthquake* b) {
        return a->latitude < b->latitude;
    };

    string to_string() {
        return "Time(" + this->sTime + "), Lat(" + std::to_string(this->latitude)  + "), Lon(" + std::to_string(this->longitude) + "), Mag(" + std::to_string(this->magnitude) + ")";
    };
};