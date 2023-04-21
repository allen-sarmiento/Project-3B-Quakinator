#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <climits>

#include "Earthquake.h"
#include "Quakinator.h"


using namespace std;

void init();
void printLogo();
void printMenu();
void printCurrentSettings();
void printSortAlgoSubMenu();
void printSortCriteriaSubMenu();

vector<string> sortAlgos, sortCriteria;
unsigned int mainOption = UINT_MAX;
unsigned int algoOption = 1;
unsigned int criteriaOption = 1;
unsigned int displayCount = 10;

int main() {

    init();

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
                // TODO
                break;
            case 4:     // Shuffle List
                // TODO
                break;
            case 5:     // Display List
                // TODO
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