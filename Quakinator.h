#pragma once

#include "Earthquake.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Quakinator {

    vector<Earthquake> array;

    int partition(int low, int high, bool (*compare)(const Earthquake&, const Earthquake&)=nullptr) {
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

    void quickSort(int low, int high, bool (*compare)(const Earthquake&, const Earthquake&)=nullptr) {
        if (low < high) {
            int pivot = partition(low, high, compare);
            quickSort(low, pivot - 1, compare);
            quickSort(pivot + 1, high, compare);
        }
    }

    void init() {
        int count = 0;
        cout << "\n";
        for (int i = 1; i <= 7; i++) {
            
            ifstream file;
            file.open("data\\query_" + to_string(i) + ".csv");
            cout << "Loading Earthquake(" << to_string(i) << ")...\n";

            string line = "";
            getline(file, line);    // Clear header line
            
            while(getline(file, line)) {
                string time, temp = "";
                double lat, lon, mag;
                stringstream tokens(line);
                getline(tokens, time, ',');
                getline(tokens, temp, ',');
                lat = stod(temp);
                getline(tokens, temp, ',');
                lon = stod(temp);
                getline(tokens, temp, ',');
                mag = stod(temp);

                count++;
                array.push_back(Earthquake(time, mag, lon, lat));
                line = "";
            }
        }
        cout << count << " EQs loaded.\n\n";
    }
};