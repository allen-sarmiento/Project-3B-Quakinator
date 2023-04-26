#pragma once

#include "Earthquake.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Quakinator {

    vector<Earthquake*> array;

    void swap(Earthquake* a, Earthquake* b) {

        Earthquake* t = a;
        a = b;
        b = t;
    }

    int partition(int low, int high, bool (*compare)(Earthquake*, Earthquake*)) {
        Earthquake* pivot = array[low];
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

    void quickSort(int low, int high, bool (*compare)(Earthquake*, Earthquake*)) {
        if (low < high) {
            int pivot = partition(low, high, compare);
            quickSort(low, pivot - 1, compare);
            quickSort(pivot + 1, high, compare);
        }
    }

    void init() {
        int testNum = 0;
        int count = 0;
        cout << "\n";
        for (int i = 1; i <= 1; i++) {
            
            ifstream file = nullptr;
            file.open("data\\query_" + to_string(i) + ".csv");
            cout << "Loading Earthquake(" << to_string(i) << ")...\n";

            string line = "";
            getline(file, line);    // Clear header line
            
            while(getline(file, line) && testNum < 5) {
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
                Earthquake* eq = new Earthquake(time, mag, lon, lat);
                array.push_back(eq);
                line = "";
                testNum++;
            }
        }
        cout << count << " EQs loaded.\n\n";

        cout << "Last EQ Loaded: " << array[array.size()-1]->to_string() << "\n\n";
    }
};