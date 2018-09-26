#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;
template <typename K, typename T>
class RankCache {
private:
    int capacity;
    unordered_map<K, T> cache;
    map<long long, unordered_set<K>> ranks;
    DataSource<K, T> ds;
public:
    RankCache(DataSource<K, T> ds, int capacity) {
        this->ds = ds;
        this->capacity = capacity;
    }
    T get(K key) {
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }
        return FetchFromDS(key);
    }
    T FetchFromDS(K key) {
        if (cache.size() == capacity) {
            auto it = ranks.begin();
            K key = *(it->second.begin());
            it->second.erase(it->second.begin());
            if (it->second.empty()) {
                ranks.erase(it);
            }
            cache.erase(key);
        }
        T val = ds.get(key);
        cache[key] = val;
        ranks[val.getRank()].insert(key);
    }
};

struct Rankable {
    long long getRank();
};
template <typename K, typename T>
struct DataSource {
    T get(K key);
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}