#include <iostream>

using namespace std;


void MySwap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int a = 10, b = 5;
    MySwap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}