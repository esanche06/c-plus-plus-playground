#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> & arr, int idx1, int idx2) {
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int findMin(vector<int> arr) {
    // Assume arr contains all positive numbers
    int min = pow(10, 5);
    for (int v : arr) {
        if (v < min) {
            min = v;
        }
    }
    return min;
}

/*
i   arr                         swap (indices)
0   [7, 1, 3, 2, 4, 5, 6]   swap (0,3)
1   [2, 1, 3, 7, 4, 5, 6]   swap (0,1)
2   [1, 2, 3, 7, 4, 5, 6]   swap (3,4)
3   [1, 2, 3, 4, 7, 5, 6]   swap (4,5)
4   [1, 2, 3, 4, 5, 7, 6]   swap (5,6)
5   [1, 2, 3, 4, 5, 6, 7]
*/

// Some number will always be < the number behind it if the array is not sorted

// For first state,
//  - diff for swapping 1,7 is 5
//  - diff for swapping 2,7 is 4 <- winner
//  - diff for swapping 3,7 is 6
//  - diff for swapping 4,7 is 6
//  - diff for swapping 5,7 is 5
//  - diff for swapping 6,7 is 5

// For second state,
//  - diff for swapping 2,1 is 0 <- winner

// For third state,
//  - diff for swapping 4,7 is 2 <- winner by default since it was the first lowest we found
//  - diff for swapping 5,7 is 2
//  - diff for swapping 6,7 is 2

// For fourth state,
//  - diff for swapping 5,7 is 1 <- winner by default since it was the first lowest we found
//  - diff for swapping 6,7 is 1

// For fifth state,
//  - diff for swapping 6,7 is 1 <- winner by default since it was the only swap we found

// Note that if diff is 0, we can stop scanning; this swap is perfect and no
// other swap will beat it

// Note that using this algo we need to find the minimum value (assuming it
// isn't always 1) so we know what the correct position of each item is


// This function is pretty inefficient, but it's what I came up with off the top of my head.
int minimumSwaps(vector<int> & arr) {
    int swaps = 0;
    int minimum = findMin(arr);
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // Looks like we have to swap something
            int minDist = arr.size() + 1;
            int swapPartner;
            // 7 6 4 5
            for (int j = i + 1; j < arr.size(); j++) {
                // Get the distance from the correct position for both values
                int combinedDist = ((arr[i] - minimum) - j) + ((arr[j] - minimum) - i);
                if (combinedDist == 0) {
                    // This is a perfect swap, we can stop searching here
                    swapPartner = j;
                    break;
                }
                else if (combinedDist < minDist) {
                    minDist = combinedDist;
                    swapPartner = j;
                }
            }
            swap(arr, i, swapPartner);
            swaps++;
            i = -1;
        }
    }
    return swaps;
}

// Below is the optimized solution to the problem.
// Courtesy https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/

// Function returns the
// minimum number of swaps
// required to sort the array
int efficientMinSwaps(vector<int> arr) {
    int n = arr.size();
    // Create an array of
    // pairs where first
    // element is array element
    // and second element
    // is position of first element
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++) {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    // Sort the array by array
    // element values to
    // get right position of
    // every element as second
    // element of pair.
    sort(arrPos, arrPos + n);

    // To keep track of visited elements.
    // Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);

    // Initialize result
    int ans = 0;

    // Traverse array elements
    for (int i = 0; i < n; i++) {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;

        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = 1;

            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }

        // Update answer by adding current cycle.
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }

    // Return result
    return ans;
}

int main()
{
    vector<int> arr = {7, 1, 3, 2, 4, 5, 6};

    int res = efficientMinSwaps(arr);

    cout << "Swaps: " << res << endl;

    for (int v : arr) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
