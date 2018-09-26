#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class BlackBox {
private:
    deque<int> nums;
    int last;
public:
    BlackBox(vector<int>& nums) {
        this->nums = deque<int>(nums.begin(), nums.end());
        last = 0;
    }
    bool getPosition() {
        if (last == 0) {
            last = (rand() % 10) >= 5 ? 2 : 1;
        }
    }
    int pop() {
        getPosition();
        int val = 0;
        if (last == 1) {
            val = nums.front();
            nums.pop_front();
        } else {
            val = nums.back();
            nums.pop_back();
        }
        last = 0;
        return val;
    }
    int peek() {
        getPosition();
        return last == 1 ? nums.front() : nums.back();
    }
    bool empty() {
        return nums.empty();
    }
};

vector<int> retrieveData(BlackBox& blackBox) {
    vector<int> smaller;
    vector<int> larger;
    while (!blackBox.empty()) {
        int temp = blackBox.pop();
        if (blackBox.empty() || temp > blackBox.peek()) {
            larger.push_back(temp);
        } else {
            smaller.push_back(temp);
        }
    }
    smaller.insert(smaller.end(), larger.rbegin(), larger.rend());
    return smaller;
}

int main() {
    vector<int> nums{1, 3, 5, 7, 9, 11, 13};
    for (auto iter = nums.rbegin(); iter != nums.rend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
    BlackBox blackBox(nums);
    auto result = retrieveData(blackBox);
    for (int num : result) {
        cout << num << endl;
    }
    return 0;
}