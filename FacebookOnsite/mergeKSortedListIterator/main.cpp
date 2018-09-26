#include <iostream>
#include <queue>

using namespace std;

class MergeListIterator {
private:
    using pairIterator = pair<vector<int>::iterator, vector<int>::iterator>;
    priority_queue<pairIterator, vector<pairIterator>, function<bool(pairIterator&, pairIterator&)>> minHeap;
public:
    MergeListIterator(vector<vector<int>>& lists) {
        minHeap = priority_queue<pairIterator, vector<pairIterator>, function<bool(pairIterator&, pairIterator&)>>(
                [](pairIterator& lhs, pairIterator& rhs) { return *(lhs.first) > *(rhs.first); });
        //这里一定要用vector<int>&
        //不能用vector<int>
        //因为拿的是iterator
        for (vector<int>& list : lists) {
            if (!list.empty()) {
                minHeap.emplace(list.begin(), list.end());
            }
        }
    }
    int next() {
        auto top = minHeap.top();
        minHeap.pop();
        auto currentBegin = top.first;
        auto currentEnd = top.second;
        int result = *currentBegin++;
        if (currentBegin != currentEnd) {
            minHeap.emplace(currentBegin, currentEnd);
        }
        return result;
    }
    bool hasNext() {
        return !minHeap.empty();
    }

};


int main() {
    vector<vector<int>> lists{{1,5,9}, {3, 7}, {2, 8}, {4,6}};
    MergeListIterator a(lists);
    while (a.hasNext()) {
        cout << a.next() << endl;
    }
    return 0;
}