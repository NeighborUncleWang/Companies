#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int val) {
//        this->val = val;
//    }
//};
//
//vector<int> mergeNList(vector<ListNode*> lists, int k) {
//    priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> minHeap(
//            [](ListNode* lhs, ListNode* rhs) { return lhs->val > rhs->val; }
//    );
//    for (auto list : lists) {
//        if (list != nullptr) {
//            minHeap.push(list);
//        }
//    }
//    vector<int> result;
//    while (!minHeap.empty()) {
//        int currentValue = minHeap.top()->val;
//        int count = 0;
//        while (!minHeap.empty() && minHeap.top()->val == currentValue) {
//            ListNode* current = minHeap.top();
//            minHeap.pop();
//            while (current && current->val == currentValue) {
//                current = current->next;
//            }
//            if (current) {
//                minHeap.push(current);
//            }
//            ++count;
//        }
//        if (count >= k) {
//            result.push_back(currentValue);
//        }
//    }
//    return result;
//}
//
using valueType = pair<vector<int>::iterator, vector<int>::iterator>;

vector<int> mergeNVector(vector<vector<int>> vecs, int k) {
    priority_queue<valueType, vector<valueType>, function<bool(valueType, valueType)>> minHeap(
            [](valueType lhs, valueType rhs) { return *(lhs.first) > *(rhs.first); }
    );
    //这里用auto vec会出bug
    //因为你push的是iterator,所以必须用auto& vec
    for (auto& vec : vecs) {
        if (!vec.empty()) {
            minHeap.emplace(vec.begin(), vec.end());
        }
    }
    vector<int> result;
    while (!minHeap.empty()) {
        int currentValue = *(minHeap.top().first);
        int count = 0;
        while (!minHeap.empty() && *(minHeap.top().first) == currentValue) {
            vector<int>::iterator current = minHeap.top().first;
            vector<int>::iterator end = minHeap.top().second;
            minHeap.pop();
            while (current != end && *current == currentValue) {
                ++current;
            }
            if (current != end) {
                minHeap.emplace(current, end);
            }
            ++count;
        }
        if (count >= k) {
            result.push_back(currentValue);
        }
    }
    return result;
}

int main() {
    vector<vector<int>> vecs{
            {1,2,3,4,5},
            {1,2,3},
            {1,2,3}
    };
    vector<int> result = mergeNVector(vecs, 3);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}