#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    int position_taken = 0;
    int n;
    int next_player = 1;
    vector<vector<char>> board;
public:
    TicTacToe(int n) {
        this->n = n;
        board = vector<vector<char>>(n, vector<char>(n, '-'));
    }
    void PrintBoard() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j > 0) {
                    cout << '|';
                }
                cout << board[i][j];
            }
            cout << endl;
        }
    }
    //player1 is user, will put 'X'
    //player2 is AI, will put 'O'
    int Add(int i, int j, int player) {
        if (i < 0 || i >= n || j < 0 || j >= n || board[i][j] != '-') {
            return -1;
        }
        if (player == 1) {
            board[i][j] = 'X';
        } else {
            board[i][j] = 'O';
        }
        ++position_taken;
        return player;
    }
    void move() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                    ++position_taken;
                    return;
                }
            }
        }
    }
    void GameLoop() {
        while (is_full() == false) {
            if (next_player == 1) {
                cout << "Please take a position as two integers:" << endl;
                int i, j;
                cin >> i;
                cin >> j;
                while (Add(i, j, 1) == -1) {
                    cout << "Invalid position, please retry:" << endl;
                    cin >> i;
                    cin >> j;
                }
            } else {
                move();
            }
            next_player = next_player == 1 ? 2 : 1;
            PrintBoard();
        }
    }
    bool is_full() {
        return position_taken == n * n;
    }
};

int main() {
    TicTacToe tic_tac_toe(3);
    tic_tac_toe.PrintBoard();
//    cout << endl;
//    tic_tac_toe.Add(0, 0, 1);
//    tic_tac_toe.Add(1, 1, 2);
//    tic_tac_toe.Add(1, 2, 1);
//    tic_tac_toe.PrintBoard();
//    tic_tac_toe.move();
//    tic_tac_toe.PrintBoard();
    tic_tac_toe.GameLoop();
    return 0;
}