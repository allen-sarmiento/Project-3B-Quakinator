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

    Earthquake(string sTime, double magnitude, double longitude, double latitude);

    void swap(int *a, int *b);
    static bool compareByTime(const Earthquake& a, const Earthquake& b);
  static  bool compareByMagnitude(const Earthquake& a, const Earthquake& b);
   static bool compareByLongitude(const Earthquake& a, const Earthquake& b);
   static bool compareByLatitude(const Earthquake& a, const Earthquake& b);
    string to_string();
};