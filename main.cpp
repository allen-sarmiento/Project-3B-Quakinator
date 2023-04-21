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
void printSortAlgoSubMenu(); // TODO
void printSortCriteriaSubMenu(); // TODO

vector<string> sortAlgos, sortCriteria;
unsigned int algoOption = 1;
unsigned int criteriaOption = 1;
unsigned int displayCount = 10;

int main() {

    unsigned int option = UINT_MAX;

    init();

    do {
        // Print menu
        printMenu();

        // Get user option
        cout << "\nEnter Option: ";
        cin >> option;
        cout << "\nOption #" << option << " selected.\n";

        switch(option) {
            case 1:     // Set Sorting Algo.
                // TODO
                break;
            case 2:     // Set Display Count
                // TODO
                break;
            case 3:     // Sort By
                // TODO
                break;
            case 4:     // Shuffle List
                // TODO
                break;
            case 5:     // Display List
                break;
        }

    } while(option != 6);

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
    cout << "[MAIN MENU]\n\n";
    cout << "1. Set Sorting Algorithm >>\n";
    cout << "2. Set Display Count\n";
    cout << "3. Sort By >>\n";
    cout << "4. Shuffle List\n";
    cout << "5. Display List\n";
    cout << "6. Exit\n\n";

    cout << "[Current Settings]\n";
    cout << "Algorithm: " << sortAlgos[algoOption-1] << "\n";
    cout << "Criteria: " << sortCriteria[criteriaOption-1] << "\n";
    cout << "Display Count: " << displayCount << "\n";
}

void printSortAlgoSubMenu() {
    cout << "[Sorting Algorithm]\n\n";
    for (int i = 0; i < sortAlgos.size(); i++)
        cout << i+1 << ". " << sortAlgos[i];
    cout << sortAlgos.size() << ". Return to Main Menu\n";
}

void printSortCriteriaSubMenu() {
    cout << "[Sort By]\n\n";
    for (int i = 0; i < sortCriteria.size(); i++)
        cout << i+1 << ". " << sortCriteria[i];
    cout << sortCriteria.size() << ". Return to Main Menu\n";
}