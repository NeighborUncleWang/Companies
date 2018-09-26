#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

class Buffer {
private:
    static constexpr int kBufferSize = 5;
    int buffer[kBufferSize];
    int read = 0, write = 0, count = 0;
    mutex shared;
    condition_variable push_cv, pop_cv;
public:
    void push(int val) {
        unique_lock<mutex> lk(shared);
        while (count == kBufferSize) {
            push_cv.wait(lk);
        }
        ++count;
        buffer[read] = val;
        read = (read + 1) % kBufferSize;
        lk.unlock();
        push_cv.notify_one();
    }
    int pop() {
        unique_lock<mutex> lk(shared);
        while (count == 0) {
            pop_cv.wait(lk);
        }
        --count;
        int val = buffer[write];
        write = (write + 1) % kBufferSize;
        lk.unlock();
        pop_cv.notify_one();
    }
};

//class Buffer {
//private:
//    const int kBufferSize = 5;
//    int buffer[kBufferSize];
//    int count = 0, add = 0, remove = 0;
//    mutex shared;
//    condition_variable push_cond;
//    condition_variable pop_cond;
//public:
//    void push(int val) {
//        unique_lock<mutex> lk(shared);
//        while (count == kBufferSize) {
//            push_cond.wait(lk);
//        }
//        cout << "in push" << endl;
//        buffer[add] = val;
//        add = (add + 1) % kBufferSize;
//        ++count;
//        lk.unlock();
//        pop_cond.notify_one();
//    }
//    void pop() {
//        unique_lock<mutex> lk(shared);
//        while (count == 0) {
//            pop_cond.wait(lk);
//        }
//        int val = buffer[remove];
//        cout << val << endl;
//        remove = (remove + 1) % kBufferSize;
//        --count;
//        lk.unlock();
//        push_cond.notify_one();
//    }
//};

int main() {
    constexpr int a = 10;
    int b[a];
    Buffer buffer;
    vector<thread> producers(5), consumers(5);
    for (int i = 0; i < 5; ++i) {
        producers[i] = thread(&Buffer::push, &buffer, i);
        consumers[i] = thread(&Buffer::pop, &buffer);
    }
    for (int i = 0; i < 5; ++i) {
        producers[i].join();
        consumers[i].join();
    }
    return 0;
}
