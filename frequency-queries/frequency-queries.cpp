#include <iostream>
#include <unordered_map>

using namespace std;


// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    // - 1 x : Insert x in your data structure.
    // - 2 y : Delete one occurence of y from your data structure, if present.
    // - 3 z : Check if any integer is present whose frequency is exactly z. If yes, print 1 else 0.
    unordered_map<int, int> frequency_map;
    unordered_map<int, int> rev_frequency_map;
    vector<int> result;

    rev_frequency_map[0] = 0;

    for (vector<int> query : queries) {
        int a = query[0], b = query[1];

        if (a == 1) {
            rev_frequency_map[frequency_map[b]] -= 1;
            frequency_map[b] += 1;
            rev_frequency_map[frequency_map[b]] += 1;
        } else if (a == 2 && frequency_map[b] > 0) {
            rev_frequency_map[frequency_map[b]] -= 1;
            frequency_map[b] -= 1;
            rev_frequency_map[frequency_map[b]] += 1;
        } else if (a == 3) {
            if (rev_frequency_map[b] > 0) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> queries = {
        {3, 5},
        {3, 3},
        {1, 10000004},
        {1, 10000016},
        {1, 10000011},
        {3, 10},
        {1, 10000006},
        {3, 5},
        {2, 4},
        {2, 3},
        {2, 6},
        {1, 10000037},
        {3, 10},
        {3, 3},
        {1, 10000013},
        {1, 10000013},
        {3, 10},
        {3, 10},
        {1, 10000025},
        {1, 10000021},
        {2, 7},
        {1, 10000002},
        {3, 7},
        {3, 9},
        {2, 9},
        {2, 8},
        {3, 4},
        {3, 4},
        {1, 10000025},
        {3, 6},
    };

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];

        if (i != ans.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}
