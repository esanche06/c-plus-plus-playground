#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std::chrono;
using namespace std;

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchantIterator(int n, vector<int> ar) {
    int pairCount = 0;

    for (int i = 0; i < n; i++) {
        if (ar[i] != -1) {
            vector<int>::iterator it = find(ar.begin() + i + 1, ar.end(), ar[i]);
            int pairIndex = it - ar.begin();

            // If pairIndex is >= to ar.size(), then ar[i] had no matching pair
            if (pairIndex < ar.size()) {
                pairCount++;
                ar[i] = -1;
                ar[pairIndex] = -1;
            }
        }
    }
    return pairCount;
}

int sockMerchantMap(int n, vector<int> ar) {
    int pairCount = 0;
    unordered_map<int, int> sockColors;

    for (int i = 0; i < n; i++) {
        if (sockColors.find(ar[i]) != sockColors.end()) {
            sockColors[ar[i]] += 1;
        } else {
            sockColors[ar[i]] = 1;
        }
    }

    for (auto i : sockColors) {
        pairCount += i.second / 2;
    }

    return pairCount;
}

int main()
{
    int n = 9;
    vector<int> ar = {10, 20, 20, 10, 10, 30, 50, 10, 20};

    auto start = high_resolution_clock::now();
    int result = sockMerchantIterator(n, ar);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time for iterator: " <<  duration.count() << endl;

    start = high_resolution_clock::now();
    result = sockMerchantIterator(n, ar);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time for map: " << duration.count() << endl;

    return 0;
}
