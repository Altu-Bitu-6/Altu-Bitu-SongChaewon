#include <iostream>
#include <stack>
#include <string>

using namespace std;

int priority(char operators) {
    if (operators == '*' || operators == '/') return 2;
    else if (operators == '+' || operators == '-') return 1;
    else return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char token : infix) {
        if (isalnum(token)) {
            postfix += token;
        }
        else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); 
        } else {
            while (!operators.empty() && priority(operators.top()) >= priority(token)) {
              // 스택의 탑에 있는 연산자의 우선순위가 더 크면 pop 후 출력
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token); // 현재 연산자를 스택에 push
        }
    }

    while (!operators.empty()) { // 남아있는 연산자를 모두 출력
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << postfix << '\n';

    return 0;
}
