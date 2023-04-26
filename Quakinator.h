#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Quakinator {

    static unordered_map<string, vector<double>> data;

    static vector<string> keys;

    static bool compareByLatitude(const string& a, const string& b) {
        return data[a][0] >= data[b][0];
    }

    static bool compareByLongitude(const string& a, const string& b) {
        return data[a][1] >= data[b][1];
    }

    static bool compareByMagnitude(const string& a, const string& b) {
        return data[a][2] >= data[b][2];
    }

    static int partition(int low, int high, bool (*compare)(const string&, const string&)) {
        string pivot = keys[low];
        int up = low+1;
        int down = high;

        while (up <= down) {
            while (up <= down && compare(keys[up], pivot))
                up++;
            while (up <= down && (!compare(keys[down], pivot)))
                down--;
            if (up < down)
                std::swap(keys[up], keys[down]);
        }
        std::swap(keys[low], keys[down]);
        return down;
    }

    static void quickSort(int low, int high, bool (*compare)(const string&, const string&)) {
        if (low < high) {
            int pivot = partition(low, high, compare);
            quickSort(low, pivot - 1, compare);
            quickSort(pivot + 1, high, compare);
        }
    }

    static void init() {
        int testNum = 0;
        int count = 0;
        cout << "\n";
        for (int i = 1; i <= 7; i++) {

            ifstream file;
            file.open("data\\query_" + to_string(i) + ".csv");
            cout << "Loading Earthquake(" << to_string(i) << ")...\n";

            string line = "";

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
                vector<double> v{lat,lon,mag};
                data[time] = v;
                keys.push_back(time);
                // keys.push_back(to_string(mag));
                line = "";
                testNum++;
            }
        }
        cout << count << " EQs loaded.\n\n";

        // cout << "Last EQ Loaded: " << to_string(data[]) << "\n\n";
    }
};
