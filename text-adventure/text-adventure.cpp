#include <array>
#include <iostream>
#include <tuple>

using namespace std;

const array<string, 9> classes = {
    "Barbarian",
    "Cleric",
    "Druid",
    "Fighter",
    "Paladin",
    "Rogue",
    "Sorceror",
    "Warlock",
    "Wizard"
};
const int numClasses = sizeof(classes) / sizeof(string);

const array<string, 3> treasures = {
    "Gleaming Sword",
    "Bubbling Potion",
    "Bag of Coins",
};
const int numTreasures = sizeof(treasures) / sizeof(string);

string askForChoiceInput(string query)
{
    string response;
    cout << query;
    cin >> response;
    return response;
}

template <size_t N>
string askForChoiceInput(string query, array<string, N> options)
{
    if (N <= 0)
    {
        // Don't ask for a choice if there are no options
        throw 1;
    }

    string response;
    cout << query;

    // If there are options, then print a newline and then list the available choices
    cout << "\n";
    for (string playerClass : options)
    {
        cout << "\t-" << playerClass << "\n";
    }

    cin >> response;
    return response;
}

bool askForYesNoInput(string query)
{
    string response;
    cout << query << " (Y/n)\n";
    cin >> response;
    return response == "Y" || response == "y";
}

template <size_t N>
int askForConsecutiveBoolInput(string query, array<string, N> effects)
{
    int i = 0;
    for (; i < N; i++)
    {
        bool yes = askForYesNoInput(query);
        if (yes)
        {
            cout << effects[i] << "\n";
        }
        else
        {
            return i;
        }
    }
    return i;
}

void intro()
{
    cout << "Welcome to Exandria adventurer!"
         << "\n";
}

string askForClass()
{
    return askForChoiceInput<>("What is your class?", classes);
}

int encounter()
{
    const int goblinResponseCount = 3;
    const array<string, goblinResponseCount> goblinResponses = {
        "The goblin brings up its shield, barely shrugging off your attack!",
        "The goblin falls to its knees, buckling under your blows!",
        "The goblin reels backwards, overwhelmed by your onslaught!",
    };

    cout << "A feral goblin crosses your path!"
         << "\n";
    int timesStruck = askForConsecutiveBoolInput<goblinResponseCount>("Do you strike the goblin?", goblinResponses);
    if (timesStruck < 3)
    {
        cout << "The goblin takes advantage of your hesitation and stabs you with its dagger!\n";
        cout << "You feel the strength sapped from your limbs as everything ";
        cout << "slowly fades to black..."
             << "\n";
        return false;
    }
    else
    {
        cout << "The goblin has been slain!"
             << "\n";
    }
    return true;
}

void treasure() {
    cout << "The goblin drops three treasures, but you only have room in ";
    cout << "your pockets for one!\n";

    string treasure = askForChoiceInput<numTreasures>("Which treasure do you choose?", treasures);

    cout << "You have chosen: " << treasure << "\n";
}

int main()
{
    // Ask for player class
    intro();

    string playerClass = askForClass();
    bool goblinSlain = encounter();

    if (goblinSlain) {
        treasure();
        cout << "Good luck on your journeys, adventurer!\n";
    }

    return 0;
}