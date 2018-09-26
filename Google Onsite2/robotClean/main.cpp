#include <iostream>

using namespace std;

struct Robot {
    bool move();
    void turnLeft(int k);
    void turnRight(int k);
    void clean();
};

class Solution {
private:
    Robot robot;
    void dfs() {
        robot.clean();
        if (robot.move()) {
            dfs();
            robot.turnLeft(2);
            robot.move();
            robot.turnLeft(2);
        }
        robot.turnLeft(1);
        if (robot.move()) {
            dfs();
            robot.turnLeft(2);
            robot.move();
            robot.turnLeft(2);
        }
        robot.turnLeft(1);
        if (robot.move()) {
            dfs();
            robot.turnLeft(2);
            robot.move();
            robot.turnLeft(2);
        }
        robot.turnLeft(1);
        if (robot.move()) {
            dfs();
            robot.turnLeft(2);
            robot.move();
            robot.turnLeft(2);
        }

    }
public:

};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}