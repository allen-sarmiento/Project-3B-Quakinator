#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <climits>
#include <algorithm>
#include <chrono>
#include "Quakinator.h"

using namespace std;

#define Q Quakinator

void init();
void printLogo();
void printMenu();
void printCurrentSettings();
void printSortAlgoSubMenu();
void printSortCriteriaSubMenu();
void printDisplayCountSubMenu();
void printDisplayListSubMenu();
void sortList();
string getEQString(string key);

unordered_map<string, vector<double>> Q::data;
vector<string> Q::keys;
int Q::criteriaIndex = 0;
vector<string> sortAlgos, sortCriteria;
unsigned int mainOption = UINT_MAX;
unsigned int algoOption = 3;
unsigned int criteriaOption = 1;
int displayCount = 10;
float duration = -1;

int main() {

    srand(time(nullptr));   // For random shuffle by time
    init();
    Q::init();

    do {
        // Print menu
        printMenu();

        switch(mainOption) {
            case 1:     // Set Sorting Algo.
                printSortAlgoSubMenu();
                break;
            case 2:     // Set Sorting Criteria
                printSortCriteriaSubMenu();
                break;
            case 3:     // Set Display Count
                printDisplayCountSubMenu();
                break;
            case 4:     // Shuffle List
                random_shuffle(Q::keys.begin(), Q::keys.end());
                cout << "\nList has been shuffled!\n\n";
                break;
            case 5:     // Display List
            {
                // Start sort clock
                auto start = chrono::high_resolution_clock::now();

                // Sort list based on criteria
                switch (algoOption) {
                    case 1:
                        std::sort(Q::keys.begin(), Q::keys.end(), Q::compare);
                        // cout << "\nSorted by STL sort.\n";
                        break;
                    case 2:
                        Q::quickSort(0, Q::keys.size()-1);
                        // cout << "\nSorted by quicksort.\n";
                        break;
                    case 3:
                        cout << "\nList was not sorted.\n";
                        break;
                }

                // End sort clock
                auto end = chrono::high_resolution_clock::now();
                duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

                // Display list
                printDisplayListSubMenu();
                
                break;
                
            }
                
            default:
                if (mainOption > 6) {
                    cout << "\nPlease enter a valid option.\n\n";
                    cout << "Enter Option: ";
                    cin >> mainOption;
                }
                break;
        }

    } while(mainOption != 6);

    return 0;
}

void init() {
    // Initialize Sorting Algorithms
    sortAlgos.push_back("STL Sort");
    sortAlgos.push_back("Quicksort");
    sortAlgos.push_back("No Sort");

    // Initialize Sorting Criteria
    sortCriteria.push_back("Time");
    sortCriteria.push_back("Magnitude");
    sortCriteria.push_back("Longitude");
    sortCriteria.push_back("Latitude");

    // Print logo on program start
    printLogo();
}

void printLogo() {
    cout << "    __" << endl;
    cout << "___( o)>" << endl;
    cout << "\\ <_. )" << endl;
    cout << " `---'" << endl;
    cout << "Quakinator by the Qua(c)kers\n";
}

void printMenu() {
    cout << "---------------------------\n";
    cout << "[Main Menu]\n";
    cout << "1. Set Sorting Algorithm >>\n";
    cout << "2. Sort By >>\n";
    cout << "3. Set Display Count\n";
    cout << "4. Shuffle List\n";
    cout << "5. Display List\n";
    cout << "6. Exit\n\n";

    cout << "[Current Settings]\n";
    cout << "Algorithm: " << sortAlgos[algoOption-1] << "\n";
    cout << "Criteria: " << sortCriteria[criteriaOption-1] << "\n";
    cout << "Display Count: " << displayCount << "\n\n";
    cout << "Enter Option: ";
    cin >> mainOption;
}

void printSortAlgoSubMenu() {
    cout << "\n---------------------------\n";
    cout << "[Sorting Algorithm]\n\n";
    for (int i = 0; i < sortAlgos.size(); i++)
        cout << i+1 << ". " << sortAlgos[i] << "\n";
    cout << sortAlgos.size()+1 << ". Return to Main Menu\n\n";

    unsigned int temp;
    cout << "Enter Option: ";
    cin >> temp;
    while(temp > sortAlgos.size()+1) {
        cout << "\nPlease enter a valid option.\n\n";
        cout << "Enter Option: ";
        cin >> temp;
    }
    algoOption = (temp == sortAlgos.size()+1) ? algoOption : temp;
}

void printSortCriteriaSubMenu() {
    cout << "\n---------------------------\n";
    cout << "[Sort By]\n\n";
    for (int i = 0; i < sortCriteria.size(); i++)
        cout << i+1 << ". " << sortCriteria[i] << "\n";
    cout << sortCriteria.size()+1 << ". Return to Main Menu\n\n";
    
    unsigned int temp;
    cout << "Enter Option: ";
    cin >> temp;
    while(temp > sortCriteria.size()+1) {
        cout << "\nPlease enter a valid option.\n\n";
        cout << "Enter Option: ";
        cin >> temp;
    }
    criteriaOption = (temp == sortCriteria.size()+1) ? criteriaOption : temp;
    Q::criteriaIndex = criteriaOption-2;
}

void printDisplayCountSubMenu() {
    cout << "\n---------------------------\n";
    cout << "[Display Count]\n\n";

    string temp;

    while (true) {

        cout << "(Enter -1 to display all earthquakes)\n";
        cout << "Enter Display Count: ";
        cin >> temp;

        try {
            displayCount = stoi(temp);
            if (displayCount < -1) throw exception();
            break;
        } catch (exception e) {
            cout << "\nError: Please enter a valid number.\n\n";
        }
    }
}

void printDisplayListSubMenu() {
    cout << "\n---------------------------\n";
    cout << "[Display List]\n\n";

    if (displayCount == -1)
        for (int i = 0; i < Q::keys.size(); i++)
            cout << i+1 << ". " << getEQString(Q::keys[i]);
    else
        for (int i = 0; i < displayCount; i++)
            cout << i+1 << ". " << getEQString(Q::keys[i]);

    cout << "\n\nSort Duration: " << duration << " milliseconds\n\n";
}

string getEQString(string key) {
    vector<double> v = Q::data[key];
    return "Time: " + key + ", Mag: " + to_string(v[0]) + ", Lon: " + to_string(v[1]) + ", Lat: " + to_string(v[2]) + "\n";
}