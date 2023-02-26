#include <iostream>
#include <string>

#include "ufo_functions.hpp"

using namespace std;

int main() {
  string codeword = "codecademy";
  string answer = string(codeword.length(), '_');
  int misses = 0;
  vector<char> incorrect;
  bool guess = false;

  greet();

  while (answer != codeword && misses < 7) {
    display_misses(misses);

    char letter;
    cout << "Please enter your guess: ";
    cin >> letter;

    for (int i = 0; i < codeword.length(); i++) {
      if (letter == codeword[i]) {
        answer[i] = letter;
        guess = true;
      }
    }

    if (guess) {
        cout << "Correct!\n";
    } else {
        cout << "Incorrect! The tractor beam pulls the person in further.\n";
        incorrect.push_back(letter);
        misses++;
    }
    guess = false;

    display_status(incorrect, answer);
  }

  end_game(answer == codeword);
}
