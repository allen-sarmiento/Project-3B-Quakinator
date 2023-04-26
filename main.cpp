#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <climits>
#include <algorithm>

#include "Earthquake.h"
#include "Quakinator.h"

using namespace std;

void init();
void printLogo();
void printMenu();
void printCurrentSettings();
void printSortAlgoSubMenu();
void printSortCriteriaSubMenu();
void printDisplayCountSubMenu();
void printDisplayListSubMenu();
void sortList(bool (*compare)(const Earthquake&, const Earthquake&));

Quakinator quakinator;
vector<string> sortAlgos, sortCriteria;
unsigned int mainOption = UINT_MAX;
unsigned int algoOption = 1;
unsigned int criteriaOption = 1;
unsigned int displayCount = 10;


int main() {

    srand(time(nullptr));   // For random shuffle by time
    init();
    quakinator.init();

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
                random_shuffle(quakinator.array.begin(), quakinator.array.end());
                cout << "\nList has been shuffled!\n\n";
                break;
            case 5:     // Display List

                // Sort list based on criteria
                switch (criteriaOption){
                    case 1:
                        sortList(Earthquake::compareByTime);
                        break;
                    case 2:
                        sortList(Earthquake::compareByMagnitude);
                        break;
                    case 3:
                        sortList(Earthquake::compareByLongitude);
                        break;
                    case 4:
                        sortList(Earthquake::compareByLatitude);
                        break;
                    default:
                        cout << "\nPlease enter a valid option.\n";
                        break;
                }

                // Display list
                printDisplayListSubMenu();
                
                break;
                
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
}

void printDisplayCountSubMenu() {
    cout << "\n---------------------------\n";
    cout << "[Display Count]\n\n";

    string temp;

    while (true) {

        cout << "Enter Display Count: ";
        cin >> temp;

        try {
            displayCount = stoi(temp);
            break;
        } catch (exception e) {
            cout << "Please enter a valid number.\n\n";
        }
    }
}

void printDisplayListSubMenu() {
    cout << "\n---------------------------\n";
    cout << "[Display List]\n\n";
    
    for (int i = 0; i < displayCount; i++)
        cout << i+1 << ". " << quakinator.array[i].to_string() << "\n";
}

void sortList(bool (*compare)(const Earthquake&, const Earthquake&)) {

    switch (algoOption) {
        case 1:
            std::sort(quakinator.array.begin(), quakinator.array.end(), compare);
            cout << "\nSorted by STL sort.\n";
            break;
        case 2:
            quakinator.quickSort(0, quakinator.array.size()-1, compare);
            cout << "\nSorted by quicksort.\n";
            break;
        default:
            cout << "\nError. No algorithm specified.";
    }
}
