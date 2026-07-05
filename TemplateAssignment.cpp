#include <iostream>
using namespace std;

// Returns the larger of two values
template <typename T>
T max_two(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

// Returns the largest of three values
template <typename T>
T max_three(T a, T b, T c)
{
    return max_two(max_two(a, b), c);
}

// Swaps the values of two variables
template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    // Testing max_two
    cout << "Largest of 5 and 8: " << max_two(5, 8) << endl;
    cout << "Largest of 3.2 and 1.7: " << max_two(3.2, 1.7) << endl;

    // Testing max_three
    cout << "Largest of 4, 9, and 2: " << max_three(4, 9, 2) << endl;
    cout << "Largest of 7.5, 2.3, and 8.1: " << max_three(7.5, 2.3, 8.1) << endl;

    // Testing swap
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}