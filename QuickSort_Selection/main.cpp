#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>


using namespace std;


void shuffle(vector<int>& nums) {
    int n = nums.size();
    for (int i = n - 1; i > 0; --) {
        int j = rand() % (i + 1);
        swap(nums[i], nums[j]);
    }
}

int partition2(vector<int>& nums, int left, int right) {
    int i = left - 1;
    int value = nums[right];
    for (int j = left; j < right; ++j) {
        if (nums[j] <= value) {
            ++i;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}

int partition(vector<int>& nums, int left, int right) {
    int val = nums[left];
    int i = left;
    int j = right + 1;
    while (true) {
        while (nums[++i] < val) {
            if (i == right) break;
        }
        while (nums[--j] > val) {
            if (j == left) break;
        }
        if (i < j) {
            swap(nums[i], nums[j]);
        } else {
            swap(nums[left], nums[j]);
            return j;
        }
    }
}

void sort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int j = partition2(nums, left, right);
    sort(nums, left, j - 1);
    sort(nums, j + 1, right);
}

void sort(vector<int>& nums) {
    int n = nums.size();
    sort(nums, 0, n - 1);
}

int select(vector<int>& nums, int left, int right, int k) {
    if (left >= right) {
        return nums[right];
    }
    int j = partition(nums, left, right);
    int i = j - left + 1;
    if (i == k) {
        return nums[j];
    } else if (i < k) {
        return select(nums, j + 1, right, k - i);
    } else {
        return select(nums, left, j - 1, k);
    }
}

int select(vector<int>& nums, int k) {
    int n = nums.size();
    return select(nums, 0, n - 1, k);
}

int main() {
    vector<int> nums{1,2,6,5,4,3};
    sort(nums);
    for (int i : nums) {
        cout << i << " ";
    }
//    cout << select(nums, 6);
}