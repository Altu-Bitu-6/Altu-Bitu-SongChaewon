#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareSerial(const string& a, const string& b) {
    int sumA = 0, sumB = 0;

    if (a.length() != b.length()) {
        return a.length() < b.length();
    }

    for (char ch : a) {
        if (isdigit(ch)) {
            sumA += ch - '0'; // 해당 숫자의 정수값으로 계산
        }
    }
    for (char ch : b) {
        if (isdigit(ch)) {
            sumB += ch - '0';
        }
    }

    if (sumA != sumB) {
        return sumA < sumB;
    }

    return a < b; // 기본 문자열 비교 계산
} 

int main() {

    int n;
    cin >> n;

    vector<string> serial(n);

    for (int i = 0; i < n; ++i) {
        cin >> serial[i];
    }

    sort(serial.begin(), serial.end(), compareSerial);

    for (const string& str : serial) {
        cout << str << endl;
    }

    return 0;
}