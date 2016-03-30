#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) { }
    Interval(int s, int e) : start(s), end(e) { }
};

class Solution {
public:
    Interval findLongest(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const Interval& lhs, const Interval& rhs) { return lhs.start < rhs.start; });
        Interval maximum;
        Interval newInterval = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= newInterval.end) {
                newInterval.end = max(newInterval.end, intervals[i].end);
            } else {
                if (newInterval.end - newInterval.start > maximum.end - maximum.start) {
                    maximum = newInterval;
                }
            }
        }
        return maximum;
    }
};


int main() {
    Solution a;
//    A in:5 out:10
//    C in:12 out: 15
//    D in: 25 out:30
//    B in:7 out:13
    vector<Interval> intervals{Interval(5,10), Interval(12,15), Interval(25,30), Interval(7,13)};
    auto result = a.findLongest(intervals);
    cout << result.start << " " << result.end;
    return 0;
}