#include <iostream>
#include <vector>

using namespace std;

// make_tuple([], 0),
// make_tuple([10, 2, 1, 9, 7, 6], 9),
// make_tuple([-11, -1, 1000, 2913], 2924),
// make_tuple([-1], 0),
// make_tuple([1], 0),
// make_tuple([-362, -23], 3339),

vector<vector<int> > test_args = {
    {},
    {10, 2, 1, 9, 7, 6},
    {-11, -1, 1000, 2913},
    {-1},
    {1},
    {-362, -23},
};

vector<int> test_expectations = {
    0,
    9,
    2924,
    0,
    0,
    339
};

int findDiffOfMinAndMax(vector<int> numbers) {
    if (numbers.size() == 0 || numbers.size() == 1) {
        return 0;
    }

    int maximum = numeric_limits<int>::max() * -1;
    int minimum = numeric_limits<int>::max();

    for (int i = 0; i < numbers.size(); i++) {
        int curr = numbers[i];
        if (curr < minimum) {
            minimum = curr;
        }
        if (curr > maximum) {
            maximum = curr;
        }
    }

    return abs(maximum - minimum);
}

int main() {
    for (int i = 0; i < test_args.size(); i++) {
        vector<int> args = test_args[i];
        int expected = test_expectations[i];
        assert(findDiffOfMinAndMax(args) == expected);
    }
}