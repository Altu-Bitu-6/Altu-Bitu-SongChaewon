#include <iostream>
#include <string>

using namespace std;

const int FULL_SET = (1 << 20) - 1; // 20번 왼쪽으로 시프트 후 1을 빼면, 20개의 1이 연속된 비트 생성

void add(int &set, int num) {
    set |= (1 << (num - 1)); // num 번째 비트를 1로 설정
}

void remove(int &set, int num) {
    set &= ~(1 << (num - 1)); // num 번째 비트를 0으로 설정
}

bool check(int set, int num) {
    return set & (1 << (num - 1)); // num 번째 비트가 1인지 확인
}

void toggle(int &set, int num) {
    set ^= (1 << (num - 1)); // num 번째 비트의 값을 반전
}

void all(int &set) {
    set = FULL_SET; // 모든 비트를 1로 설정
}

void empty(int &set) {
    set = 0; // 모든 비트를 0으로 설정
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m, num;
    string op;
    cin >> m;

    int set = 0; // 집합을 나타내는 변수, 초기에는 비어있음

    for (int i = 0; i < m; ++i) {
        cin >> op;
        if (op == "add") {
            cin >> num;
            add(set, num);
        } else if (op == "remove") {
            cin >> num;
            remove(set, num);
        } else if (op == "check") {
            cin >> num;
            cout << check(set, num) << '\n';
        } else if (op == "toggle") {
            cin >> num;
            toggle(set, num);
        } else if (op == "all") {
            all(set);
        } else if (op == "empty") {
            empty(set);
        }
    }

    return 0;
}
