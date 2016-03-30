#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        next = nullptr;
    }
};

void swapLargestTwo(ListNode* head) {
    ListNode dummyNode(0);
    ListNode* dummy = &dummyNode;
    dummy->next = head;
    ListNode* firstMinPredecessor = dummy;
    ListNode* secondMinPredecessor = dummy;
    auto iter = dummy;
    while (iter->next != nullptr) {
        if (iter->next->val < firstMinPredecessor->next->val) {
            secondMinPredecessor = firstMinPredecessor;
            firstMinPredecessor = iter;
        } else if (iter->next->val < secondMinPredecessor->next->val) {
            secondMinPredecessor = iter;
        }
        iter = iter->next;
    }
    auto firstMinElement = firstMinPredecessor->next;
    auto secondMinElement = secondMinPredecessor->next;
    firstMinPredecessor->next = secondMinElement;
    secondMinPredecessor->next = firstMinElement;
    auto next = firstMinElement->next;
    firstMinElement->next = secondMinElement->next;
    secondMinElement->next = next;
}

void printList(ListNode* head) {
    auto iter = head;
    while (iter) {
        cout << iter->val << " -> ";
        iter = iter->next;
    }
    cout << endl;
}

int main() {
    vector<int> nums{10,9,8,7,5,6,10,4};
    ListNode dummyNode(-1);
    ListNode* dummy = &dummyNode;
    auto iter = dummy;
    for (int num : nums) {
        iter->next = new ListNode(num);
        iter = iter->next;
    }
    printList(dummy->next);
    swapLargestTwo(dummy->next);
    printList(dummy->next);
    return 0;
}