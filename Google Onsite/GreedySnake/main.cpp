#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct

class GreedySnake {
private:
    int rowSize;
    int columnSize;
    vector<pair<int, int>> food;
    string moves;
public:
    GreedySnake(int row, int column, vector<pair<int, int>>& food, string& moves) {
        rowSize = row;
        columnSize = column,
        this->food = food;
        moves = moves;
    }
    int gameScore() {
        int column = columnSize;
        int row = rowSize;
        unordered_set<pair<int, int>, function<int(pair<int, int>)>> hashSet(10, [=](pair<int, int> position) {
            return position.first * column + position.second; });

    }
};



int main() {
    cout << "Hello, World!" << endl;
    return 0;
}