#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Function to get a valid integer from the player
int getGuess() {
  int guess;
  while (true) {
    cout << "Choose a number from 1 to 100: ";
    cin >> guess;

    if (cin.fail()) {
      cout << "Please enter a valid number!" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      return guess;
    }
  }
}

// Function to play a single round of guessing game
bool playRound() {
  int number = rand() % 100 + 1; // Random number between 1 and 100
  int chances = 6;

  cout << "\n A new game has started! You have 6 chances to guess the number.";

  while (chances > 0) {
    cout << "Chances left: " << chances << endl;
    int guess = getGuess();

    if (guess > number) {
      cout << "Too high!" << endl;
    } else if (guess < number) {
      cout << "Too low!" << endl;
    } else {
      cout << "You guessed it right!" << endl;
      return true; // Player won
    }
    chances--;
  }
  cout << "You lose! The number was " << number << ". Try again next time."
       << endl;
  return false; // Player lost
}

// Main game loop
void playGame() {
  cout << "Welcome to the Number Guessing Game!" << endl;

  while (true) {
    playRound();

    string contCheck;
    cout << "Do you want to play again? (yes/no): ";
    getline(cin, contCheck);

    // Convert to lowercse for comparison
    for (char &c : contCheck) {
      c = tolower(c);
    }
    // Trim white space
    size_t start = contCheck.find_first_not_of(" \t\n\r");
    size_t end = contCheck.find_last_not_of(" \t\n\r");
    if (start != string::npos && end != string::npos) {
      contCheck = contCheck.substr(start, end - start + 1);
    }

    if (contCheck != "yes") {
      cout << "Thanks for playing! Goodbye!" << endl;
      break;
    }
  }
}

int main() {
  // Seed the random number generator
  srand(static_cast<unsigned int>(time(0)));

  playGame();

  return 0;
}
