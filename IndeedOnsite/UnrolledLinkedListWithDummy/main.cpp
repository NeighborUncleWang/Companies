#include <iostream>
#include <vector>

using namespace std;

struct Node {
    vector<char> chars = vector<char>(5);
    int length = 0;
    Node* next = nullptr;
};

class LinkedList {
private:
    Node* head = new Node();
    int totalLength = 0;
public:
    char get(int index) {
        if (index >= totalLength || index < 0) {
            throw out_of_range("index out of range");
        }
        int currentIndex = 0;
        Node* iter = head;
        while (iter != nullptr) {
            if (currentIndex + iter->length - 1 >= index) {
                break;
            }
            currentIndex += iter->length;
            iter = iter->next;
        }
        return iter->chars[index - currentIndex];
    }
    void insert(char ch, int index) {
        if (index > totalLength || index < 0) {
            throw out_of_range("index out of range");
        }
        Node dummyNode;
        Node* dummy = &dummyNode;
        dummy->next = head;
        Node* iter = dummy;
        int currentIndex = 0;
        while (iter->next) {
            if (currentIndex + 4 >= index) {
                break;
            }
            currentIndex += iter->next->length;
            iter = iter->next;
        }
        if (iter->length == 5) {
            auto next = iter->next;
            iter->next = new Node;
            iter->next->chars[0] = iter->chars.back();
            iter->next->next = next;
            iter->next->length = 1;
            iter->chars.insert(iter->chars.begin() + index - currentIndex, ch);
            iter->chars.resize(5);
        } else {
            iter->chars.insert(iter->chars.begin() + index - currentIndex, ch);
            iter->chars.resize(5);
            ++iter->length;
        }
        ++totalLength;
    }
    void print() {
        auto iter = head;
        while (iter) {
            for (char ch : iter->chars) {
                cout << ch << " ";
            }
            cout << "| ";
            iter = iter->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    for (int i = 0; i < 6; ++i) {
        list.insert('a' + i, 0);
        list.print();
    }
    return 0;
}