#include <iostream>
#include <vector>

using namespace std;

void rotateWheel(vector<char>& data, int& index, int num) { // 바퀴 돌리는 함수
    index = (index + num) % data.size();
}

void printResult(vector<char>& data, int index) { // 결과 출력하는 함수
    for (int i = 0; i < data.size(); ++i) {
        cout << data[index];
        index = (index - 1 + data.size()) % data.size();
    }
}

bool checkDuplicate(vector<char>& data) { // 중복된 글자 확인하는 함수
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == '?') {
            continue;
        }
        for (int j = i + 1; j < data.size(); ++j) {
            if (data[i] == data[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<char> data(n, '?');
    int index = 0;
    bool check = true;

    for (int i = 0; i < k; ++i) {
        int num;
        char alphabet;
        
        cin >> num >> alphabet;

        rotateWheel(data, index, num);

        if (data[index] != '?') {
            if (data[index] == alphabet) {
                continue;
            }
            check = false;
        } else {
            data[index] = alphabet;
        }
    }

    if (check && !checkDuplicate(data)) {
        printResult(data, index);
    } else {
        cout << '!';
    }

    return 0;
}
