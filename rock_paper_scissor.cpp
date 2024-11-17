#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int main() {
    // Initialize random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Declare variables
    int userChoice, computerChoice;
    string choices[] = {"Rock", "Paper", "Scissors"};

    // Introduction
    cout << "Welcome to Rock, Paper, Scissors Game!" << endl;
    cout << "Enter your choice:" << endl;
    cout << "1. Rock\n2. Paper\n3. Scissors\n";
    cout << "Enter a number (1-3): ";
    cin >> userChoice;

    // Validate user input
    if (userChoice < 1 || userChoice > 3) {
        cout << "Invalid choice. Please select 1, 2, or 3." << endl;
        return 1;
    }

    // Generate computer's choice (randomly 1 to 3)
    computerChoice = rand() % 3 + 1;

    // Display choices
    cout << "You chose: " << choices[userChoice - 1] << endl;
    cout << "Computer chose: " << choices[computerChoice - 1] << endl;

    // Determine winner
    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == 1 && computerChoice == 3) || 
               (userChoice == 2 && computerChoice == 1) || 
               (userChoice == 3 && computerChoice == 2)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }

    return 0;
}
