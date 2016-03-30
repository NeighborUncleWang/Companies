// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <queue>
#include <vector>

using namespace std;

int isPath(int **grid, int m, int n)
{
    // WRITE YOUR CODE HERE
    if (m == 0 || n == 0) return 0;
    if (grid[0][0] == 9) return 1;
    int diffX[4] = {-1, 0, 1, 0};
    int diffY[4] = {0, -1, 0, 1};
    queue<long long> pointsQueue;
    pointsQueue.push(0);
    grid[0][0] = 0;
    while (!pointsQueue.empty()) {
        long long currentPoint = pointsQueue.front();
        int currentX = currentPoint / n;
        int currentY = currentPoint % n;
        pointsQueue.pop();
        for (int i  = 0; i < 4; ++i) {
            int nextX = currentX + diffX[i];
            int nextY = currentY + diffY[i];
            if (nextX >= 0 && nextX < m
                && nextY >= 0 && nextY < n) {
                if (grid[nextX][nextY] == 9) {
                    return 1;
                } else if (grid[nextX][nextY] == 1) {
                    pointsQueue.push(nextX * n + nextY);
                    grid[nextX][nextY] = 0;
                }
            }
        }
    }
    return 0;
}
// FUNCTION SIGNATURE ENDS