#include <iostream>
#include <vector>

using namespace std;

int getIndex(vector<int> v, int k) {
    auto it = find(v.begin(), v.end(), k);

    // If element was found
    if (it != v.end())
    {
        // calculating the index
        // of K
        return it - v.begin();
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}

int getIndex(vector<int> v, int k, int start) {
    vector<int>::iterator it = find(v.begin() + start, v.end(), k);
    // If element was found
    if (it != v.end())
    {
        // calculating the index
        // of K
        return it - v.begin();
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
}

int main() {
    // Vector
    vector<int> v = { 1, 45, 54, 71, 76, 54, 17 };
    // Value whose index
    // needs to be found
    int K = 54;
    cout << getIndex(v, K) << "\n";
    cout << getIndex(v, K, 3) << "\n";
    cout << getIndex(v, 3) << "\n";

    return 0;
}