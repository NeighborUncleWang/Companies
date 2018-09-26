#include <iostream>

using namespace std;

template<typename T>
T MyMax(const T& a, const T& b) {
    return a < b ? b : a;
//    return greater<int> ? a : b;
}

int main() {
    int a = 10, b = 100;
    cout << greater<int>(100, 10);
    cout << MyMax(10, 100);
    return 0;
}