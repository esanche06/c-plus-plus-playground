#include <iostream>

using namespace std;

// Let's follow a "boxes in cubbies" analogy for these examples...

// Here, we take out the boxes a* and b*, and swap their contents, a and b...
template <typename T>
void value_by_ref_swap_practice(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// Here, we take out the boxes a* and b*, take out their contents a and b, and swap the *cubby*
// each box is in, but the contents of each box is in the same cubby it started in...
template <typename T>
void pointer_by_ref_swap_practice(T*& a, T*& b) {
    T *temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 0, b = 1;
    int *aPtr = &a, *bPtr = &b;

    cout << a << " VS. " << b << "\n";
    cout << aPtr << " VS. " << bPtr << "\n";

    value_by_ref_swap_practice(a, b);

    cout << a << " VS. " << b << "\n";
    cout << aPtr << " VS. " << bPtr << "\n";

    pointer_by_ref_swap_practice(aPtr, bPtr);

    cout << a << " VS. " << b << "\n";
    cout << aPtr << " VS. " << bPtr << "\n";

    return 0;
}