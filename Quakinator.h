#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <chrono>

using namespace std;

struct Quakinator {

    // 0: mag, 1: lon, 2: lat
    static unordered_map<string, vector<double>> data;
    static vector<string> keys;
    static int criteriaIndex;

    static bool compare(const string& a, const string& b) {
        // cout << "CI: " << criteriaIndex << "\n";
        if (criteriaIndex >= 0)
            return data[a][criteriaIndex] >= data[b][criteriaIndex];
        return (a.compare(b) >= 0);
    }

    static int partition(int low, int high) {

        string pivotKey = keys[low];

        int up = low+1;
        int down = high;

        while (up <= down) {
            while (compare(keys[up], pivotKey)) 
                up++;
            while (up <= down && !compare(keys[down], pivotKey))
                down--;
            if (up < down)
                std::swap(keys[up], keys[down]);
        }
        std::swap(keys[low], keys[down]);
        return down;
    }

    static void quickSort(int low, int high) {
        if (low < high) {
            int pivot = partition(low, high);
            quickSort(low, pivot - 1);
            quickSort(pivot + 1, high);
        }
    }

    static void init() {
        int count = 0;
        cout << "\n";
        for (int i = 1; i <= 7; i++) {
            ifstream file;
            file.open("data\\query_" + to_string(i) + ".csv");
            cout << "Loading Earthquake(" << to_string(i) << ")...\n";
            string line = "";

            while(getline(file, line)) {
                string time = "", temp = "";
                double lat = -1, lon = -1, mag = -1;
                stringstream tokens(line);
                getline(tokens, time, ',');
                getline(tokens, temp, ',');
                lat = stod(temp);
                getline(tokens, temp, ',');
                lon = stod(temp);
                getline(tokens, temp, ',');
                mag = stod(temp);
                
                count++;
                data[time] = {mag,lon,lat};
                keys.push_back(time);
                line = "";
            }
        }
        cout << count << " EQs loaded.\n\n";
    }
};
