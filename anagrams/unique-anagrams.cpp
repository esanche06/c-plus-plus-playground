#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;


int anagrams(string s) {
    int n = s.length();
    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++) {
        string sb = "";

        for (int j = i; j < n; j++) {
            // Set substring as sb + the new character, sorted
            sb = sb + s[j];
            sort(sb.begin(), sb.end());

            mp[sb] = mp[sb];

            // Increment map value
            mp[sb] += 1;
        }
    }

    int anas = 0;

    for (auto kv : mp) {
        string k = kv.first;
        int v = kv.second;

        cout << k << " " << v << endl;

        anas += floor((v*(v-1))/2);
    }

    return anas;
}

int main()
{
    cout << anagrams("abba") << endl;

    return 0;
}
