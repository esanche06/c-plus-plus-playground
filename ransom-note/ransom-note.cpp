#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// This could probably be optimized, but it does pass all tests from the
// original prompt
void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> magazine_word_count;
    unordered_map<string, int> note_word_count;

    for (string v : magazine) {
        if (magazine_word_count.find(v) != magazine_word_count.end()) {
            magazine_word_count[v] += 1;
        } else {
            magazine_word_count[v] = 1;
        }
    }

    for (string v : note) {
        if (note_word_count.find(v) != note_word_count.end()) {
            note_word_count[v] += 1;
        } else {
            note_word_count[v] = 1;
        }
    }

    for (pair<string, int> kv : note_word_count) {
        // Word is not in the magazine, so print No
        if (magazine_word_count.find(kv.first) == magazine_word_count.end()) {
            cout << "No" << endl;
            return;
        }
        // Magazine does not have enough of word, so print No
        if (kv.second > magazine_word_count[kv.first]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main()
{
    vector<string> magazine = {"ive", "got",  "a",  "lovely",  "bunch",  "of",  "coconuts"};
    vector<string> note = {"ive", "got", "some", "coconuts"};

    checkMagazine(magazine, note);

    return 0;
}
