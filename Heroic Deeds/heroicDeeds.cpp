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
                // TODO: Implement addHeroicDeed()
                addHeroicDeed(heroicDeeds, serviceBranches);
                break;
            case 2:
                // TODO: Implement displayDeeds()
                displayDeeds(heroicDeeds, serviceBranches);
                break;
            case 3:
                // TODO: Implement displayStatistics()
                displayStatistics(heroicDeeds, serviceBranches);
                break;
            case 4:
                // TODO: Implement createPatrioticPattern()
                createPatrioticPattern();
                break;
            case 5:
                // TODO: Implement searchByBranch()
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

// TODO: Implement the displayBanner() function
void displayBanner() {
    cout << "========================================\n";
    cout << "      VETERANS DAY TRIBUTE PROGRAM      \n";
    cout << "========================================\n";
    cout << "   Honoring Those Who Served Our Nation\n";
    cout << "========================================\n\n";
}

// TODO: Implement addHeroicDeed() function
void addHeroicDeed(vector<string>& deeds, vector<string>& branches) {
    // Steps:
    // 1. Ask user to enter branch
    // 2. Ask user to describe heroic deed
    // 3. Store data in vectors
}

// TODO: Implement displayDeeds() function
void displayDeeds(const vector<string>& deeds, const vector<string>& branches) {
    // Steps:
    // 1. Check if vectors are empty
    // 2. Loop through vectors and print deeds with branch
}

// TODO: Implement displayStatistics() function
void displayStatistics(const vector<string>& deeds, const vector<string>& branches) {
    // Steps:
    // 1. Count total deeds
    // 2. Count deeds by branch
    // 3. Display results
}

// TODO: Implement createPatrioticPattern() function
void createPatrioticPattern() {
    // Steps:
    // 1. Ask user for number of rows
    // 2. Use loops to print a pattern (★, ●, ▲)
}

// TODO: Implement searchByBranch() function
void searchByBranch(const vector<string>& deeds, const vector<string>& branches) {
    // Steps:
    // 1. Ask user for branch to search
    // 2. Loop through branches vector and display matching deeds
}
