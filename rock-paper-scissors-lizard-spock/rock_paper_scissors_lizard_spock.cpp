#include <iostream>
#include <stdlib.h>

using namespace std;

const string rock = "✊";
const string paper = "✋";
const string scissors = "✌️";
const string lizard = "🤏";
const string spock = "🖖";

int getUserChoice() {
  int user;

  cout << "====================\n";
  cout << "rock paper scissors!\n";
  cout << "====================\n";

  cout << "1) " << rock << "\n";
  cout << "2) " << paper << "\n";
  cout << "3) " << scissors << "\n";
  cout << "4) " << lizard << "\n";
  cout << "5) " << spock << "\n";

  cout << "shoot! ";
  cin >> user;
  return user;
}

string getEmojiFromChoice(int choice) {
  switch (choice) {
    case 1:
      return rock;
    case 2:
      return paper;
    case 3:
      return scissors;
    case 4:
      return lizard;
    case 5:
      return spock;
    default:
      return "❓";
  }
}

void printVsText(int user, int cpu) {
  string userEmoji = getEmojiFromChoice(user);
  string cpuEmoji = getEmojiFromChoice(cpu);
  cout << userEmoji << "\tVS.\t" << cpuEmoji << "\n";
}

bool checkRockVsOpponent(int opponent) {
  return opponent == 3 || opponent == 4;
}

bool checkPaperVsOpponent(int opponent) {
  return opponent == 1 || opponent == 5;
}

bool checkScissorsVsOpponent(int opponent) {
  return opponent == 2 || opponent == 4;
}

bool checkLizardVsOpponent(int opponent) {
  return opponent == 2 || opponent == 5;
}

bool checkSpockVsOpponent(int opponent) {
  return opponent == 1 || opponent == 3;
}

bool doesUserWin(int userChoice, int cpuChoice) {
  switch (userChoice) {
    case 1:
      return checkRockVsOpponent(cpuChoice);
    case 2:
      return checkPaperVsOpponent(cpuChoice);
    case 3:
      return checkScissorsVsOpponent(cpuChoice);
    case 4:
      return checkLizardVsOpponent(cpuChoice);
    case 5:
      return checkSpockVsOpponent(cpuChoice);
    default:
      // Could print out a cheeky message here as well...
      return false;
  }
}

/*
In this game, we recreate the classic game of:
Rock-Paper-Scissors-Lizard-Spock!!!
*/
int main() {
  srand (time(NULL));

  int computer = rand() % 3 + 1;
  int user = getUserChoice();
  printVsText(user, computer);
  bool userWins = doesUserWin(user, computer);

  if (userWins) {
    cout << "Congrats, you've won!" << "\n";
  } else {
    cout << "Sorry, better luck next time!" << "\n";
  }

  return 0;
}
