#include <iostream>
#include <string>

using namespace std;

const int SIX_SIX_SIX = 666;

string getTitle(int order) {
    int currentNumber = 665;  // 666이 영화 제목에 사용된 경우도 있기에 665부터 시작
    while (order > 0) {
        currentNumber++;

        // 현재 숫자에 666이 포함되어 있으면 order를 감소시킴
        if (to_string(currentNumber).find("666") != string::npos) {
            order--;
        }
    }

    return to_string(currentNumber);
}

int main() {
    int order;
    cin >> order;

    string movieTitle = getTitle(order);

    cout << movieTitle << '\n';

    return 0;
}
