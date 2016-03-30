#include <iostream>
#include <vector>

using namespace std;

//Fisher–Yates shuffle Algorithm
void shuffle(vector<int>& nums) {
    int n = nums.size();
    //use current time as the seed
    srand(time(0));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);// random integer j where <= j <= i
        swap(nums[i], nums[j]);
    }
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    shuffle(nums);
    for (int i : nums) {
        cout << i << " ";
    }
    return 0;
}