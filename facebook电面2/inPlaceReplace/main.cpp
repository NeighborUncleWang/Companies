#include <iostream>

using namespace std;

void replace(string& s) {
    int store_index = 0;
    for (int i = 0; i < s.size(); ++store_index) {
        if (i < (int)s.size() - 2 && s.substr(i, 3) == "%20") {
            s[store_index] = ' ';
            i += 3;
        } else {
            s[store_index] = s[i++];
        }
    }
    s.resize(store_index);
}

int main() {
    string s = "abc%20def";
    replace(s);
    cout << s << endl;
    s = "abc%20%20%2";
    replace(s);
    cout << s << endl;
    return 0;
}