#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void insertionSort(vector<T>& nums) {
    int size = nums.size();
    for (int i = 1; i < size; ++i) {
        T val = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > val) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = val;
    }
}

template <typename T>
void bucketSort(vector<T>& nums) {
    int n = nums.size();
    vector<vector<T>> buckets(n);
    T minNum = *min_element(nums.begin(), nums.end());
    T maxNum = *max_element(nums.begin(), nums.end());
    for (T num : nums) {
        //这里最后得乘以(n - 1)而不是n
        //否则num == maxNum的时候index==n
        //就越界了
        //但是为什么一开始写成n的时候程序没有报错?
        int index = (num - minNum) * 1.0 / (maxNum - minNum) * (n - 1);
        buckets[index].push_back(num);
    }
    for (int i = 0; i < n; ++i) {
        insertionSort(buckets[i]);
    }
    vector<T> result;
    for (vector<T>& bucket : buckets) {
        result.insert(result.end(), bucket.begin(), bucket.end());
    }
    nums = move(result);
}

int main() {
    vector<double> nums{0.9, 0.8, 0.6, 0.7, 0.5, 0.1, 0.2, 0.3, 0.4};
    bucketSort(nums);
    for (double num : nums) {
        cout << num << " ";
    }
    cout << endl;
    vector<int> nums2{10,9,8,7,6,5,4,3,2,1,0};
    bucketSort(nums2);
    for (int num : nums2) {
        cout << num << " ";
    }
    return 0;
}