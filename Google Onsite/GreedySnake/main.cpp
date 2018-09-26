#include <iostream>
#include <vector>
#include <unordered_set>
#include <deque>
#include <unordered_map>

using namespace std;

class GreedySnake {
public:
    int gameScore(int row, int column, vector<pair<int, int>>& food, string& moves) {
        unordered_set<pair<int, int>, function<int(pair<int, int>)>> hashSet({{0, 0}}, 10, [=](pair<int, int> position) {
            return position.first * column + position.second; });
        auto foodIter = food.begin();
        //不能只存head 和 tail两个变量,必须用deque
        //否则pop尾巴的时候不知道新的尾巴是什么
        deque<pair<int, int>> snake{{0, 0}};
        unordered_map<char, pair<int, int>> moveMap{
                {'U', {-1, 0}},
                {'D', {1, 0}},
                {'L', {0, -1}},
                {'R', {0, 1}}
        };
        for (char ch : moves) {
            auto head = snake.front();
            auto next = make_pair(head.first + moveMap[ch].first, head.second + moveMap[ch].second);
            if (next.first < 0 || next.first >= row || next.second < 0 || next.second >= column) {
                return hashSet.size() - 1;
            } else if (next == *foodIter) {
                if (hashSet.find(next) != hashSet.end()) {
                    return hashSet.size();
                }
                hashSet.insert(next);
                snake.push_front(next);
                if (++foodIter == food.end()) {
                    return hashSet.size() - 1;
                }
            } else {
                hashSet.erase(snake.back());
                snake.pop_back();
                if (hashSet.find(next) != hashSet.end()) {
                    return hashSet.size() - 1;
                }
                hashSet.insert(next);
                snake.push_front(next);
            };
        }
        return hashSet.size() - 1;
    }
};



int main() {
    GreedySnake a;
    vector<pair<int, int>> food{{0,1}, {0,2}, {0,3},{1,3},{2,3},{3,3}};
    string move("RRRDDD");
    cout << a.gameScore(4, 4, food, move);
    return 0;
}