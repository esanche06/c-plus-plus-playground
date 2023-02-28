#include <iostream>
#include <vector>

using namespace std;

vector<int> rotLeftSpecialCase(vector<int> a, int d) {
    for (int i = 0; i < d; i++) {
        int temp = a[i];
        a[i] = a[d + i];
        a[d + i] = temp;
    }
    return a;
}

vector<int> rotLeftInPlace(vector<int> a, int d) {
    int n = a.size();

    if (d == n / 2) {
        return rotLeftSpecialCase(a, d);
    }

    int currIdx = 0;
    int currVal = a[currIdx];
    for (int i = 0; i < n; i++) {
        int rotIdx = currIdx - d;
        int newIdx = rotIdx < 0 ? n + rotIdx : rotIdx;
        int temp = a[newIdx];
        a[newIdx] = currVal;
        currVal = temp;
        currIdx = newIdx;
    }
    return a;
}

vector<int> rotLeft(vector<int> a, int d) {
    for (int i = 0; i < d; i++) {
        a.push_back(a[0]);
        a.erase(a.begin());
    }
    return a;
}

vector<int> rotRight(vector<int> a, int d) {
    for (int i = 0; i < d; i++) {
        a.insert(a.begin(), a.back());
        a.pop_back();
    }
    return a;
}

int main() {
    vector<int> a = {41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51};
    int d = 10;

    for (int x : rotLeftInPlace(a, d)) {
        cout << x << " ";
    }
    cout << endl;

    for (int x : rotLeft(a, d)) {
        cout << x << " ";
    }
    cout << endl;

    for (int x : rotRight(a, 5)) {
        cout << x << " ";
    }
    cout << endl;

    // 77 97 58 1 86 58 26 10 86 51 41 73 89 7 10 1 59 58 84 77

    return 0;
}