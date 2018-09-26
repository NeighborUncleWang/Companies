#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    int partition(vector<pair<int, int>>& points, int start, int end) {
        auto comp = [](pair<int, int>& lhs, pair<int, int>& rhs) {
            return (long long) lhs.first * lhs.first + lhs.second * rhs.second <
                   (long long) rhs.first * rhs.first + rhs.second * rhs.second;
        };
        auto val = points[end];
        int i = start - 1;
        for (int j = start; j < end; ++j) {
            if (comp(points[j], val)) {
                swap(points[++i], points[j]);
            }
        }
        swap(points[i + 1], points[end]);
        return i + 1;
    }
    int selection(vector<pair<int, int>>& points, int start, int end, int k) {
        if (start == end) return start;
        int pivot = partition(points, start, end);
        int count = pivot - start + 1;
        if (count == k) {
            return pivot;
        } else if (count < k) {
            return selection(points, pivot + 1, end, k - count);
        } else {
            return selection(points, start, pivot - 1, k);
        }
    }
public:
    vector<pair<int, int>> FindKNearestPointsToOrigin(vector<pair<int, int>>& points, int k) {
        auto comp = [](pair<int, int>& lhs, pair<int, int>& rhs) {
            return (long long)lhs.first * lhs.first + lhs.second * rhs.second >
                    (long long)rhs.first * rhs.first + rhs.second * rhs.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(points.begin(), points.end(), comp);
        vector<pair<int, int>> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
    vector<pair<int, int>> FindKNearestPointsToOrigin2(vector<pair<int, int>>& points, int k) {
        auto comp = [](pair<int, int>& lhs, pair<int, int>& rhs) {
            return (long long)lhs.first * lhs.first + lhs.second * rhs.second <
                   (long long)rhs.first * rhs.first + rhs.second * rhs.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
        for (auto& point : points) {
            heap.push(point);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        vector<pair<int, int>> res;
        while (!heap.empty()) {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
    vector<pair<int, int>> FindKNearestPointsToOrigin3(vector<pair<int, int>>& points, int k) {
        int pivot = selection(points, 0, points.size() - 1, k);
        return vector<pair<int, int>>(points.begin(), points.begin() + pivot + 1);
    }
};

int main() {
    Solution a;
    vector<pair<int, int>> points{{1, 0}, {0, 1}, {2,0}, {0, 2}, {3, 0}, {0, 3}, {4, 0}};
    auto res1 = a.FindKNearestPointsToOrigin(points, 4);
    auto res2 = a.FindKNearestPointsToOrigin2(points, 4);
    auto res3 = a.FindKNearestPointsToOrigin2(points, 4);
    sort(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());
    sort(res3.begin(), res3.end());
    cout << (res1 == res2) << endl;
    cout << (res1 == res3) << endl;
    return 0;
}