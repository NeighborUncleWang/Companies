#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;
template <typename T>
class RandomNumberGenerator {
private:
    vector<T> nums;
public:
    RandomNumberGenerator(vector<T>& nums) {
        this->nums = nums;
    }
    int nextInteger(int random) {
        vector<int> map;
        for (int i = 0; i < nums.size(); ++i) {
            map.insert(map.end(), nums[i], i);
        }
//        for (int num : map) {
//            cout << num << " ";
//        }
//        cout << endl;
//        int random = rand() % map.size();
        return map[random];
    }
    int nextInteger2(T random) {
        vector<T> sums = nums;
        for (int i = 1; i < sums.size(); ++i) {
            sums[i] += sums[i - 1];
        }
//        for (int sum : sums) {
//            cout << sum << " ";
//        }
//        cout << endl;
//        int random = rand() % sums.back();
        double random2 = ((double)rand() / RAND_MAX) * sums.back();
        int low = 0;
        int high = (int)sums.size() - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (sums[middle] > random) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }
        return low;
    }
};

int main() {
    vector<int> nums{1,4,2,6};
    RandomNumberGenerator<int> r(nums);
//    int totalSum = accumulate(nums.begin(), nums.end(), 0);
//    for (int i = 0; i < totalSum; ++i) {
//        cout << "i= " << i << " out= " << r.nextInteger2(i) << endl;
//    }
//
//    for (int i = 0; i < totalSum; ++i) {
//        cout << "i= " << i << " out= " << r.nextInteger(i) << endl;
//    }
    vector<double> nums2{0.1, 0.4, 0.2, 0.6};
    RandomNumberGenerator<double> r2(nums2);
    double totalSum2 = accumulate(nums2.begin(), nums2.end(), 0.0);
    for (double i = 0; i < totalSum2; i += 0.1) {
        cout << "i= " << i << " out= " << r2.nextInteger2(i) << endl;
    }
    return 0;
}