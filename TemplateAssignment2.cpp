#include <iostream>
#include <vector>
#include <functional>
#include <cassert>
#include <string>
using namespace std;

// Fills a vector with elem, elem+1, elem+2, ...
template <typename T>
vector<T> vec_fill(T elem)
{
    vector<T> v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(elem + i);
    }

    return v;
}

// Repeatedly applies func until predicate is true
template <typename T>
T until(T elem, function<T(T)> func, function<bool(T)> predicate)
{
    while (!predicate(elem))
    {
        elem = func(elem);
    }

    return elem;
}

// Swaps two values
template <typename T>
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Orders three values from largest to smallest
template <typename T>
void order(T& a, T& b, T& c)
{
    if (a < b)
        mySwap(a, b);

    if (a < c)
        mySwap(a, c);

    if (b < c)
        mySwap(b, c);
}

int main()
{
    //==========================
    // vec_fill Tests
    //==========================

    vector<int> vi = vec_fill(5);
    assert(vi[0] == 5);
    assert(vi[9] == 14);

    vector<double> vd = vec_fill(2.5);
    assert(vd[0] == 2.5);
    assert(vd[9] == 11.5);

    vector<char> vc = vec_fill('A');
    assert(vc[0] == 'A');
    assert(vc[9] == 'J');

    //==========================
    // until Tests
    //==========================

    assert(until<int>(
        1,
        [](int x) { return x + 1; },
        [](int x) { return x >= 10; }) == 10);

    assert(until<double>(
        1.0,
        [](double x) { return x + 0.5; },
        [](double x) { return x >= 3.0; }) == 3.0);

    assert(until<char>(
        'A',
        [](char c) { return char(c + 1); },
        [](char c) { return c == 'F'; }) == 'F');

    //==========================
    // order Tests
    //==========================

    int a = 3, b = 8, c = 5;
    order(a, b, c);
    assert(a == 8 && b == 5 && c == 3);

    double d = 1.2, e = 5.4, f = 2.8;
    order(d, e, f);
    assert(d == 5.4 && e == 2.8 && f == 1.2);

    char x = 'B', y = 'Z', z = 'M';
    order(x, y, z);
    assert(x == 'Z' && y == 'M' && z == 'B');

    cout << "All tests passed!" << endl;

    return 0;
}