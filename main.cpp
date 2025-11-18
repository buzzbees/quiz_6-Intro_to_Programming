#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

// Structure for veteran information
struct Veteran {
    string name;
    int age;
    vector<string> medals; // Each veteran can have multiple medals
};

// Function prototypes
void displayBanner();
void addVeteran(vector<Veteran>& veterans);
void displayVeterans(const vector<Veteran>& veterans);
void searchByMedal(const vector<Veteran>& veterans);
void medalStatistics(const vector<Veteran>& veterans);
void removeVeteran(vector<Veteran>& veterans);
void sortVeteransByAge(vector<Veteran>& veterans);

int main() {
    vector<Veteran> veterans;
    int choice;
    
    displayBanner();

    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Add a veteran and their medals\n";
        cout << "2. Display all veterans and medals\n";
        cout << "3. Search veterans by medal\n";
        cout << "4. Show medal statistics\n";
        cout << "5. Remove a veteran by name\n";
        cout << "6. Sort veterans by age\n";
        cout << "7. Exit\n";
        cout << "Choose an option (1-7): ";
        cin >> choice;
        cin.ignore(); // clear newline

        switch(choice) {
            case 1: addVeteran(veterans); break;
            case 2: displayVeterans(veterans); break;
            case 3: searchByMedal(veterans); break;
            case 4: medalStatistics(veterans); break;
            case 5: removeVeteran(veterans); break;
            case 6: sortVeteransByAge(veterans); break;
            case 7: cout << "Thank you for honoring our veterans!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 7);

    return 0;
}

// Implement displayBanner()
void displayBanner() {
    cout << "****************************************\n";
    cout << "*  Veteran Recognition Program         *\n";
    cout << "*  Honoring those who served           *\n";
    cout << "****************************************\n";
}

// Implement addVeteran()
void addVeteran(vector<Veteran>& veterans) {
    Veteran newVeteran;
    cout << "Enter veteran's name: ";
    getline(cin, newVeteran.name);
    cout << "Enter veteran's age: ";
    cin >> newVeteran.age;
    cin.ignore(); // clear newline

    int numMedals;
    cout << "Enter number of medals: ";
    cin >> numMedals;
    cin.ignore(); // clear newline

    for (int i = 0; i < numMedals; ++i) {
        string medalName;
        cout << "Enter name of medal " << (i + 1) << ": ";
        getline(cin, medalName);
        // Check for duplicate medals
        if (find(newVeteran.medals.begin(), newVeteran.medals.end(), medalName) == newVeteran.medals.end()) {
            newVeteran.medals.push_back(medalName);
        } else {
            cout << "Medal '" << medalName << "' already added for this veteran. Skipping.\n";
        }
    }
    veterans.push_back(newVeteran);
    cout << "Veteran added successfully.\n";
}

// Implement displayVeterans()
void displayVeterans(const vector<Veteran>& veterans) {
    if (veterans.empty()) {
        cout << "No veterans to display.\n";
        return;
    }
    cout << "\n=== ALL VETERANS ===\n";
    for (const auto& veteran : veterans) {
        cout << "Name: " << veteran.name << ", Age: " << veteran.age << "\n";
        cout << "Medals: ";
        if (veteran.medals.empty()) {
            cout << "None\n";
        } else {
            for (const auto& medal : veteran.medals) {
                cout << medal << (medal == veteran.medals.back() ? "" : ", ");
            }
            cout << "\n";
        }
        cout << "--------------------\n";
    }
}

// Implement searchByMedal()
void searchByMedal(const vector<Veteran>& veterans) {
    if (veterans.empty()) {
        cout << "No veterans to search.\n";
        return;
    }
    string searchMedal;
    cout << "Enter medal to search for: ";
    getline(cin, searchMedal);

    bool found = false;
    cout << "\nVeterans with " << searchMedal << ":\n";
    for (const auto& veteran : veterans) {
        if (find(veteran.medals.begin(), veteran.medals.end(), searchMedal) != veteran.medals.end()) {
            cout << "- " << veteran.name << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No veterans found with that medal.\n";
    }
}

// Implement medalStatistics()
void medalStatistics(const vector<Veteran>& veterans) {
    if (veterans.empty()) {
        cout << "No veterans to collect medal statistics from.\n";
        return;
    }
    map<string, int> medalCounts;
    for (const auto& veteran : veterans) {
        for (const auto& medal : veteran.medals) {
            medalCounts[medal]++;
        }
    }

    cout << "\n=== MEDAL STATISTICS ===\n";
    if (medalCounts.empty()) {
        cout << "No medals awarded yet.\n";
        return;
    }
    for (const auto& pair : medalCounts) {
        cout << pair.first << ": " << pair.second << " times awarded\n";
    }
}

// Implement removeVeteran()
void removeVeteran(vector<Veteran>& veterans) {
    if (veterans.empty()) {
        cout << "No veterans to remove.\n";
        return;
    }
    string veteranToRemove;
    cout << "Enter the name of the veteran to remove: ";
    getline(cin, veteranToRemove);

    auto it = remove_if(veterans.begin(), veterans.end(),
                        [&](const Veteran& v) { return v.name == veteranToRemove; });

    if (it != veterans.end()) {
        veterans.erase(it, veterans.end());
        cout << "Veteran '" << veteranToRemove << "' removed successfully.\n";
    } else {
        cout << "Veteran '" << veteranToRemove << "' not found.\n";
    }
}

// Implement sortVeteransByAge()
void sortVeteransByAge(vector<Veteran>& veterans) {
    if (veterans.empty()) {
        cout << "No veterans to sort.\n";
        return;
    }
    sort(veterans.begin(), veterans.end(), [](const Veteran& a, const Veteran& b) {
        return a.age < b.age;
    });
    cout << "Veterans sorted by age (ascending).\n";
    displayVeterans(veterans); // Display sorted list
}
