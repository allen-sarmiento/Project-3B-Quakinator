#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

struct Quakinator {

    // Using time string as keys
    static unordered_map<string, vector<double>> data;

    vector<string> keys;

    static bool compareByLatitude(string a, string b) {
        return data[a][0] < data[b][0];
    };

    static bool compareByLongitude(string a, string b) {
        return data[a][1] < data[b][1];
    };

    static  bool compareByMagnitude(string a, string b) {
        return data[a][2] < data[b][2];
    };

    /*
    void swap(Earthquake& a, Earthquake& b) {
        Earthquake t = a;
        a = b;
        b = t;
    }

    int partition(int low, int high, bool (*compare)(Earthquake&, Earthquake&)) {
        // Earthquake pivot = array.at(low);
        int up = low;
        int down = high;

        while (up < down) {
            for (int j = up; j < high; j++) {
                if (compare(array.at(j), array.at(low))) {
                    break;
                }
                up++;
            }
            for (int j = high; j > low; j--) {
                if (!compare(array.at(j), array.at(low))) {
                    break;
                }
                down--;
            }
            if (up < down) {
                std::swap(array.at(up), array.at(down));
            }
        }
        std::swap(array.at(low), array.at(down));
        return down;
    }

    void quickSort(int low, int high, bool (*compare)(Earthquake&, Earthquake&)) {
        if (low < high) {
            int pivot = partition(low, high, compare);
            quickSort(low, pivot - 1, compare);
            quickSort(pivot + 1, high, compare);
        }
    }
    */

    void init() {
        int testNum = 0;
        int count = 0;
        cout << "\n";
        for (int i = 1; i <= 1; i++) {
            
            ifstream file = nullptr;
            file.open("data\\query_" + to_string(i) + ".csv");
            cout << "Loading Earthquake(" << to_string(i) << ")...\n";

            string line = "";
            // getline(file, line);    // Clear header line
            
            while(getline(file, line) && true) {
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
                data[time] = {lat,lon,mag};
                keys.push_back(time);
                line = "";
                testNum++;
            }
        }
        cout << count << " EQs loaded.\n\n";

        // cout << "Last EQ Loaded: " << to_string(data[]) << "\n\n";
    }
};