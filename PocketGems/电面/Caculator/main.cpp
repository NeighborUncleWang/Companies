#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

class Solution {
public:
    int Caculator(string expression) {
        stack<char> ops;
        stack<int> values;
        for (int i = 0; i < expression.size(); ++i) {
            if (isdigit(expression[i])) {
                int num = 0;
                while (i < expression.size() && isdigit(expression[i])) {
                    num = num * 10 + expression[i++] - '0';
                }
                --i;
                values.push(num);
            } else if (expression[i] == '(') {
                ops.push(expression[i]);
            } else if (expression[i] == ')') {
                while (ops.top() != '(') {
                    ApplyOp(ops, values);
                }
                ops.pop();
            } else {
                while (!ops.empty() && hasPrecedence(ops.top(), expression[i])) {
                    ApplyOp(ops, values);
                }
                ops.push(expression[i]);
            }
        }
        while (!ops.empty()) {
            ApplyOp(ops, values);
        }
        return values.top();
    }

private:
    void ApplyOp(stack<char>& ops, stack<int>& values) {
        int second = values.top();
        values.pop();
        int first = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        int value = 0;
        switch (op) {
            case '+':
                value = first + second;
                break;
            case '-':
                value = first - second;
                break;
            case '*':
                value = first * second;
                break;
            case '/':
                value = first / second;
                break;
            case '^':
                value = pow(first, second);
                break;
            default:
                break;
        }
        values.push(value);
    }
    //if op1 has same or greater precedence than op2
    //return true;
    bool hasPrecedence(char op1, char op2) {
       if (op2 == '^' && op1 != '^') {
           return false;
       } else if ((op2 == '*' || op2 == '/') && (op1 == '+' || op1 == '-')) {
           return false;
       } else if (op1 == '(') {
           return false;
       } else {
           return true;
       }
    }
};

int main() {
    Solution a;
    cout << a.Caculator("6+1+(25/5+3)^2") << endl;
    return 0;
}