#include <iostream>

using namespace std;


int matchAnagram(string s1, string s2) {
    int count = 0, i = 0;
    unordered_map<char, int> s1_map, s2_map;

    while ((i < s1.length()) || (i < s2.length())) {
        if (i < s1.length()) {
            s1_map[s1[i]] += 1;
            // Make sure the other map has this character as a key so we can easily compare later
            s2_map[s1[i]] += 0;
        }
        if (i < s2.length()) {
            s2_map[s2[i]] += 1;
            // Make sure the other map has this character as a key so we can easily compare later
            s1_map[s2[i]] += 0;
        }
        i += 1;
    }

    for (auto kv : s1_map) {
        count += abs(s1_map[kv.first] - s2_map[kv.first]);
    }

    return count;
}

int main()
{
    string a, b;

    int res = matchAnagram(a, b);


    return 0;
}
