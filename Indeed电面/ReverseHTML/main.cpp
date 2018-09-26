#include <iostream>
#include <string>


using namespace std;


void reverseHTML(string& s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ';') {
            int j = i + 1;
            while (j < s.size() && s[j] != '&') {
                if (s[j] == ';') {
                    i = j;
                }
                ++j;
            }
            if (j < s.size()) {
                reverse(s.begin() + i, s.begin() + j + 1);
            }
            i = j;
        }
    }
}

int main() {
    string s = "&a&b&c&d&amp;a;b;c;d; &&&&&&offer;;;;;";
    reverseHTML(s);
    cout << s << endl;
    s = "1234&euro;";
    reverseHTML(s);
    cout << s << endl;
    s = "1234&euro";
    reverseHTML(s);
    cout << s << endl;
    s = "1234&euro;567";
    reverseHTML(s);
    cout << s << endl;
}