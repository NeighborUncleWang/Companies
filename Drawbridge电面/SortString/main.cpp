#include <iostream>
#include <vector>

using namespace std;

int main() {
    function<bool(string, string)> comparator = [](string lhs, string rhs) {
        if (lhs.size() != rhs.size()) {
            return lhs.size() < rhs.size();
        } else {
            reverse(lhs.begin(), lhs.end());
            reverse(rhs.begin(), rhs.end());
            return lhs < rhs;
        }
    };
    vector<string> input{"1234", "4123", "12"};
    sort(input.begin(), input.end(), comparator);
    for (string& s : input) {
        cout << s << endl;
    }
    return 0;
}