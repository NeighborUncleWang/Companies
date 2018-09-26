#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTable {
private:
    int entries_count = 0;
    int hash(int key) {
        int res = 0;
        while (key) {
            res = res * 31 + key % 10;
            key /= 10;
        }
        return res;
    }
    vector<list<pair<int, int>>> buckets = vector<list<pair<int, int>>>(8);
public:
    int get(int key) {
        int index = abs(hash(key)) % buckets.size();
        for (auto& it : buckets[index]) {
            if (it.first == key) {
                return it.second;
            }
        }
    }
    void put(pair<int, int> entry) {
        if (entries_count * 1.0 / buckets.size() >= 0.5) {
            resize();
        }
        int index = abs(hash(entry.first)) % buckets.size();
        for (auto& it : buckets[index]) {
            if (it.first == entry.first) {
                it.second = entry.second;
                return;
            }
        }
        ++entries_count;
        buckets[index].push_back(entry);
    }
    void resize() {
        cout << "resize called, entries_count = " << entries_count << "bucket_size = " << buckets.size() << endl;
        auto temp = buckets;
        buckets = vector<list<pair<int, int>>>(buckets.size() * 2);
        nri
        for (auto& bucket : temp) {
            for (auto& it : bucket) {
                put(it);
            }
        }
    }
};

int main() {
    HashTable ht;
    for (int i = 0; i < 10; ++i) {
        ht.put({i, i});
    }
    return 0;
}