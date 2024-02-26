#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 우선순위 반환 함수
int getPriority(char op) {
    if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0; // 피연산자는 가장 낮은 우선순위
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char token : infix) {
        // 피연산자는 그대로 출력
        if (isalnum(token)) {
            postfix += token;
        }
        // 연산자 처리
        else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            // '('를 만날 때까지 스택에서 연산자를 pop하여 출력
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // '(' 제거
        } else {
            // 스택의 top에 있는 연산자의 우선순위가 더 크면 pop 후 출력
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(token)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token); // 현재 연산자를 스택에 push
        }
    }

    // 남아있는 연산자를 모두 출력
    while (!operators.empty()) {
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
