#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next = nullptr, *pre = nullptr;
    ListNode(int val) {
        this->val = val;
    }
};
class MyStack {
private:
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    unsigned int size = 0;
public:
    void push(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
        ++size;
    }
    void pop() {
        auto pre = tail->pre;
        pre->next = nullptr;
        delete tail;
        --size;
    }
    int peek() {
        if (tail == dummy) {
            throw invalid_argument("invalid syntax");
        }
        return tail->val;
    }
    bool empty() {
        return size == 0;
    }
};
class MinStack {
private:
    MyStack min_st;
    MyStack st;
public:
    void push(int val) {
        if (min_st.empty() || val <= min_st.peek()) {
            min_st.push(val);
        }
        st.push(val);
    }
    void pop() {
        if (st.peek() == min_st.peek()) {
            min_st.pop();
        }
        st.pop();
    }
    int min() {
        return min_st.peek();
    }
    int peek() {
        return st.peek();
    }
};


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}