#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
void displayBanner();
void addHeroicDeed(vector<string>& deeds, vector<string>& branches);
void displayDeeds(const vector<string>& deeds, const vector<string>& branches);
void displayStatistics(const vector<string>& deeds, const vector<string>& branches);
void createPatrioticPattern();
void searchByBranch(const vector<string>& deeds, const vector<string>& branches);

int main() {
    vector<string> heroicDeeds;
    vector<string> serviceBranches;
    int choice;

    // Display program banner
    displayBanner();

    do {
        // Main menu
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Add a veteran's heroic deed\n";
        cout << "2. Display all heroic deeds\n";
        cout << "3. Show tribute statistics\n";
        cout << "4. Create patriotic pattern\n";
        cout << "5. Search deeds by branch\n";
        cout << "6. Exit\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;
        cin.ignore();  // clear newline

        switch(choice) {
            case 1:
                addHeroicDeed(heroicDeeds, serviceBranches);
                break;
            case 2:
                displayDeeds(heroicDeeds, serviceBranches);
                break;
            case 3:
                displayStatistics(heroicDeeds, serviceBranches);
                break;
            case 4:
                createPatrioticPattern();
                break;
            case 5:
                searchByBranch(heroicDeeds, serviceBranches);
                break;
            case 6:
                cout << "Thank you for honoring our veterans!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 6);

    return 0;
}

// Display program banner
void displayBanner() {
    cout << "========================================\n";
    cout << "      VETERANS DAY TRIBUTE PROGRAM      \n";
    cout << "========================================\n";
    cout << "   Honoring Those Who Served Our Nation\n";
    cout << "========================================\n\n";
}

// Add a heroic deed
void addHeroicDeed(vector<string>& deeds, vector<string>& branches) {
    string branch, deed;

    cout << "Enter the veteran's service branch (Army, Navy, Air Force, Marines, Coast Guard, Space Force): ";
    getline(cin, branch);

    cout << "Describe the heroic deed: ";
    getline(cin, deed);

    deeds.push_back(deed);
    branches.push_back(branch);

    cout << "Heroic deed added successfully.\n";
}

// Display all deeds
void displayDeeds(const vector<string>& deeds, const vector<string>& branches) {
    if (deeds.empty()) {
        cout << "No heroic deeds recorded yet.\n";
        return;
    }

    cout << "\n=== HEROIC DEEDS LIST ===\n";
    for (size_t i = 0; i < deeds.size(); i++) {
        cout << i + 1 << ". [" << branches[i] << "] " << deeds[i] << "\n";
    }
}

// Display statistics
void displayStatistics(const vector<string>& deeds, const vector<string>& branches) {
    if (deeds.empty()) {
        cout << "No statistics available. No deeds recorded.\n";
        return;
    }

    int total = deeds.size();
    int army = 0, navy = 0, air = 0, marines = 0, coast = 0, space = 0;

    for (const string& b : branches) {
        if (b == "Army") army++;
        else if (b == "Navy") navy++;
        else if (b == "Air Force") air++;
        else if (b == "Marines") marines++;
        else if (b == "Coast Guard") coast++;
        else if (b == "Space Force") space++;
    }

    cout << "\n=== TRIBUTE STATISTICS ===\n";
    cout << "Total heroic deeds: " << total << "\n";
    cout << "Army: " << army << "\n";
    cout << "Navy: " << navy << "\n";
    cout << "Air Force: " << air << "\n";
    cout << "Marines: " << marines << "\n";
    cout << "Coast Guard: " << coast << "\n";
    cout << "Space Force: " << space << "\n";
}

// Create simple patriotic pattern
void createPatrioticPattern() {
    int rows = 5;

    cout << "\nPATRIOTIC PATTERN:\n";

    for (int i = 1; i <= rows; i++) {
        if (i % 2 == 1)
            cout << "★ ★ ★ ★ ★\n";   // odd rows
        else
            cout << "===== =====\n"; // even rows
    }
}

// Search deeds by branch
void searchByBranch(const vector<string>& deeds, const vector<string>& branches) {
    if (deeds.empty()) {
        cout << "No deeds to search.\n";
        return;
    }

    string searchBranch;
    cout << "Enter the branch to search for: ";
    cin.ignore();
    getline(cin, searchBranch);

    cout << "\n=== SEARCH RESULTS FOR " << searchBranch << " ===\n";
    bool found = false;

    for (size_t i = 0; i < deeds.size(); i++) {
        if (branches[i] == searchBranch) {
            cout << "- " << deeds[i] << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No heroic deeds found for this branch.\n";
    }
}
