#include <iostream>

using namespace std;

template <typename T>
void swap_practice(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 0, b = 1;

    cout << a << " VS. " << b << "\n";

    swap_practice(a, b);

    cout << a << " VS. " << b << "\n";

    return 0;
}