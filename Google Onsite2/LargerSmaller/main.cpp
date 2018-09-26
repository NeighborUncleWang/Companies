#include <iostream>
#include <vector>
using namespace std;

//void printLargerSmaller(const vector<int> &v) {
//    int n = v.size();
//    vector<int>leftMax(n, INT_MIN);
//    for(int i=1;i<n; ++i) leftMax[i]  = max(leftMax[i-1], v[i-1]);
//    int rightMin = INT_MAX;
//    for(int i=n-1;i>=0; i--)  {
//        if(i<n-1)rightMin = min(rightMin, v[i+1]);
//        if(v[i] >leftMax && v < rightMin) cout << v << " ";
//    }
//}
//












void myVersion(const vector<int>& nums) {
    int n = nums.size();
    vector<int> left_max(n, INT_MIN);
    for (int i = 1; i < n; ++i) {
        left_max[i] = max(left_max[i - 1], nums[i - 1]);
    }
    int left_min = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        if (nums[i] < left_min && nums[i] > left_max[i]) cout << nums[i] << endl;
        left_min = min(left_min, nums[i]);
    }
}

int main() {
    vector<int>v = {3,4,7,1,8,12};
    myVersion(v);
    return 0;
}