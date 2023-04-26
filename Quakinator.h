#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Quakinator {
    static unordered_map<string, vector<double>> data;

    vector<string> keys;

    vector<double> mags;

    static bool compareByLatitude(const string& a, const string& b) {
        return data[a][0] < data[b][0];
    }

    static bool compareByLongitude(const string& a, const string& b) {
        return data[a][1] < data[b][1];
    }

    static bool compareByMagnitude(const string& a, const string& b) {
        return data[a][2] < data[b][2];
    }

    static bool compareByMagnitude2(const double& a, const double& b) {
        return a < b;
    }

    void swap(string& a, string& b) {
        string t = a;
        a = b;
        b = t;
    }
    int Magpartition(int low, int high, bool (*compare)(const string&, const string&)) {
        int up = low;
        int down = high;

        while (up < down) {
            for (int j = up; j < high; j++) {
                if (compare(keys[j], keys[low])) {
                    break;
                }
                up++;
            }
            for (int j = high; j > low; j--) {
                if (!compare(keys[j], keys[low])) {
                    break;
                }
                if (down > 0)
                    down--;
            }
            if (up < down) {
                std::swap(keys[up], keys[down]);
            }
        }
        std::swap(keys[low], keys[down]);
        return down;
    }

    int partition(int low, int high, bool (*compare)(const string&, const string&)) {
        int up = low;
        int down = high;

        while (up < down) {
            for (int j = up; j < high; j++) {
                if (compare(keys[j], keys[low])) {
                    break;
                }
                up++;
            }
            for (int j = high; j > low; j--) {
                if (!compare(keys[j], keys[low])) {
                    break;
                }
                if (down > 0)
                    down--;
            }
            if (up < down) {
                std::swap(keys[up], keys[down]);
            }
        }
        std::swap(keys[low], keys[down]);
        return down;
    }

    void quickSort(int low, int high, bool (*compare)(const string&, const string&)) {
        if (low < high) {
            if (low < 0)
                cout << "LOW IS OUT OF BOUNDS: " << low << "\n";
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
                data[time] = {lat,lon,mag};
                keys.push_back(time);
                mags.push_back(mag);
                line = "";
                testNum++;
            }
        }
        cout << count << " EQs loaded.\n\n";

        // cout << "Last EQ Loaded: " << to_string(data[]) << "\n\n";
    }
};
