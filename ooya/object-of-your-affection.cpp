#include <iostream>
#include "profile.hpp"

using namespace std;

int main() {
    Profile ethan("Ethan Sanchez", "Carlsbad", "USA", "He/Him", 26);
    ethan.printProfile();
    return 0;
}