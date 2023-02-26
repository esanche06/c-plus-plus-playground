#include <iostream>
#include <vector>

#include "ufo_functions.hpp"

using namespace std;

// Define functions

void greet() {
  cout << "=============\n";
  cout << "UFO: The Game\n";
  cout << "=============\n";
  cout << "Instructions: save your friend from alien abduction by guessing the letters in the codeword.\n";
}

void display_status(vector<char> incorrect, string answer) {
    cout << "Incorrect Guesses: ";
    for (char c : incorrect) {
      cout << c << " ";
    }

    cout << "\n";

    cout << "Codeword: ";
    for (char s : answer) {
      cout << s << " ";
    }
    cout << "\n";
}

void end_game(bool playerWon) {
    string winMsg = "Hooray! You saved the person and earned a medal of honor!\n";
    string loseMsg = "Oh no! The UFO just flew away with another person!\n";
    string resultMsg = playerWon ? winMsg : loseMsg;
    cout << resultMsg;
}

void display_misses(int misses) {

  if (misses == 0 || misses == 1) {

    cout << "                 .                            \n";
    cout << "                 |                            \n";
    cout << "              .-\"^\"-.                       \n";
    cout << "             /_....._\\                       \n";
    cout << "         .-\"`         `\"-.                  \n";
    cout << "        (  ooo  ooo  ooo  )                   \n";
    cout << "         '-.,_________,.-'    ,-----------.   \n";
    cout << "              /     \\        (  Send help! ) \n";
    cout << "             /   0   \\      / `-----------'  \n";
    cout << "            /  --|--  \\    /                 \n";
    cout << "           /     |     \\                     \n";
    cout << "          /     / \\     \\                   \n";
    cout << "         /               \\                   \n";

  }
  else if (misses == 2) {

    cout << "                 .                            \n";
    cout << "                 |                            \n";
    cout << "              .-\"^\"-.                       \n";
    cout << "             /_....._\\                       \n";
    cout << "         .-\"`         `\"-.                  \n";
    cout << "        (  ooo  ooo  ooo  )                   \n";
    cout << "         '-.,_________,.-'    ,-----------.   \n";
    cout << "              /  0  \\        (  Send help! ) \n";
    cout << "             / --|-- \\      / `-----------'  \n";
    cout << "            /    |    \\    /                 \n";
    cout << "           /    / \\    \\                    \n";
    cout << "          /             \\                    \n";
    cout << "         /               \\                   \n";

  }
  else if (misses == 3) {

    cout << "                 .                            \n";
    cout << "                 |                            \n";
    cout << "              .-\"^\"-.                       \n";
    cout << "             /_....._\\                       \n";
    cout << "         .-\"`         `\"-.                  \n";
    cout << "        (  ooo  ooo  ooo  )                   \n";
    cout << "         '-.,_________,.-'    ,-----------.   \n";
    cout << "              /--|--\\        (  Send help! ) \n";
    cout << "             /   |   \\      / `-----------'  \n";
    cout << "            /   / \\   \\    /                \n";
    cout << "           /           \\                     \n";
    cout << "          /             \\                    \n";
    cout << "         /               \\                   \n";

  }
  else if (misses == 3) {

    cout << "                 .                            \n";
    cout << "                 |                            \n";
    cout << "              .-\"^\"-.                       \n";
    cout << "             /_....._\\                       \n";
    cout << "         .-\"`         `\"-.                  \n";
    cout << "        (  ooo  ooo  ooo  )                   \n";
    cout << "         '-.,_________,.-'    ,-----------.   \n";
    cout << "              /--|--\\        (  Send help! ) \n";
    cout << "             /   |   \\      / `-----------'  \n";
    cout << "            /   / \\   \\    /                \n";
    cout << "           /           \\                     \n";
    cout << "          /             \\                    \n";
    cout << "         /               \\                   \n";

  }
  else if (misses == 4) {

    cout << "                 .                            \n";
    cout << "                 |                            \n";
    cout << "              .-\"^\"-.                       \n";
    cout << "             /_....._\\                       \n";
    cout << "         .-\"`         `\"-.                  \n";
    cout << "        (  ooo  ooo  ooo  )                   \n";
    cout << "         '-.,_________,.-'    ,-----------.   \n";
    cout << "              /  |  \\        (  Send help! ) \n";
    cout << "             /  / \\  \\      / `-----------' \n";
    cout << "            /         \\    /                 \n";
    cout << "           /           \\                     \n";
    cout << "          /             \\                    \n";
    cout << "         /               \\                   \n";

  }
  else if (misses == 5) {

    cout << "                 .                            \n";
    cout << "                 |                            \n";
    cout << "              .-\"^\"-.                       \n";
    cout << "             /_....._\\                       \n";
    cout << "         .-\"`         `\"-.                  \n";
    cout << "        (  ooo  ooo  ooo  )                   \n";
    cout << "         '-.,_________,.-'    ,-----------.   \n";
    cout << "              / / \\ \\        (  Send help! )\n";
    cout << "             /       \\      / `-----------'  \n";
    cout << "            /         \\    /                 \n";
    cout << "           /           \\                     \n";
    cout << "          /             \\                    \n";
    cout << "         /               \\                   \n";

  }
  else if (misses == 6) {

    cout << "                 .                            \n";
    cout << "                 |                            \n";
    cout << "              .-\"^\"-.                       \n";
    cout << "             /_....._\\                       \n";
    cout << "         .-\"`         `\"-.                  \n";
    cout << "        (  ooo  ooo  ooo  )                   \n";
    cout << "         '-.,_________,.-'    ,-----------.   \n";
    cout << "              /     \\        (  Send help! ) \n";
    cout << "             /       \\      / `-----------'  \n";
    cout << "            /         \\    /                 \n";
    cout << "           /           \\                     \n";
    cout << "          /             \\                    \n";
    cout << "         /               \\                   \n";

  }

}