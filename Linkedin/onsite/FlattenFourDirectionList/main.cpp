#include <iostream>

using namespace std;

struct MultiListNode {
    int val;
    MultiListNode* pre;
    MultiListNode* next;
    MultiListNode* up;
    MultiListNode* down;
};

class Solution {
public:
    void convert(MultiListNode* current) {
        if (current == nullptr) return;
        auto head = GetHead(current);
        auto tail = GetTail(current);
        auto iter = head;
        while (iter != tail) {
            if (iter->up) {
                auto new_head = GetHead(iter->up);
                auto new_tail = GetTail(iter->up);
                tail->next = new_head;
                new_head->pre = tail;
                tail = new_tail;
                iter->up->down = nullptr;
                iter->up = nullptr;
            }
            if (iter->down) {
                auto new_head = GetHead(iter->down);
                auto new_tail = GetTail(iter->down);
                tail->next = new_head;
                new_head->pre = tail;
                tail = new_tail;
                iter->down->up = nullptr;
                iter->down = nullptr;
            }
            iter = iter->next;
        }

    }

private:
    MultiListNode* GetHead(MultiListNode* head) {
        auto slow = head;
        auto fast = head;
        while (fast && fast->pre) {
            fast = fast->pre;
        }
        return head;
    }
    MultiListNode* GetTail(MultiListNode* tail) {
        while (tail->next) {
            tail = tail->pre;
        }
        return tail;
    }
};


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}