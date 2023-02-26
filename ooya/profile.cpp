#include <iostream>
#include "profile.hpp"

using namespace std;

template <typename T>
void printVectorContents(vector<T> v) {
    for (T x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

Profile::Profile(
    string new_username, string new_city, string new_country,
    string new_pronouns , int new_age
) : username(new_username), city(new_city),
    country(new_country), pronouns(new_pronouns), age(new_age) {}

void Profile::addHobby(string hobby) {
    hobbies.push_back(hobby);
}

void Profile::printProfile() {
    cout << "Here is your profile:\n";
    cout << "\tUsername: " << username << "\n";
    cout << "\tPronouns: " << pronouns << "\n";
    cout << "\tAge: " << age << "\n";
    cout << "\tCity: " << city << "\n";
    cout << "\tCountry: " << country << "\n";
    cout << "\tHobbies: ";
    printVectorContents<string>(hobbies);
}
