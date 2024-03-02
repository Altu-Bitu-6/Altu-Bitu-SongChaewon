#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& str) {
    stack<char> s; // 괄호를 저장

    for (char bracket : str) {
        if (bracket == '(' || bracket == '[') {
            s.push(bracket);
        } else if (bracket == ')' || bracket == ']') {
            if (s.empty() || (bracket == ')' && s.top() != '(') || (bracket == ']' && s.top() != '[')) {
                return false;
            }
            s.pop(); // 짝이 맞으면 스택에서 제거
        }
    }

    return s.empty(); // 모든 괄호의 짝이 맞으면 스택이 비어있어야 함
}

int main() {
  
    string line;

    while (true) {
        getline(cin, line);

        if (line == ".") { 
            break;
        }

        if (isBalanced(line)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
