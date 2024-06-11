
#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int evaluateExpression( string expression) {
    stack<int> s;
    stringstream ss(expression);
    string t;

    while (getline(ss, t, ',')) {
        if (t == "+") {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            s.push(operand1 + operand2);
        } else if (t == "-") {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            s.push(operand1 - operand2);
        } else if (t == "*") {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            s.push(operand1 * operand2);
        } else if (t == "/") {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            if (operand2 != 0) {
                s.push(operand1 / operand2);
            } else {
                cerr << "Division by zero error!" << endl;
                return 0;
            }
        } else {
            s.push(stoi(t));
        }
    }

    if (s.size() == 1) {
        return s.top();
    } else {
        cerr << "Invalid expression!" << endl;
        return 0;
    }
}

int main() {
    string expression;
    cout<<"enter postfix expression for evaluate:"<<endl;
    cin>>expression;
    int result = evaluateExpression(expression);
    cout << " evaluate Result: " << result << endl;
    return 0;
}
