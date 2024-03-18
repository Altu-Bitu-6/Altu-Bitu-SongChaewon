#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) { // 최대공약수(gcd) 구하는 함수
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int differenceGcd(const vector<int>& numbers) { // 숫자의 차이의 최대공약수 구하기 
    vector<int> differences;
    for (int i = 1; i < numbers.size(); ++i) {
        differences.push_back(numbers[i] - numbers[i - 1]);
    }

    int result = differences[0];
    for (int i = 1; i < differences.size(); ++i) {
        result = gcd(result, differences[i]);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> numbers(n);
    
    for (int i = 0; i < n; ++i) { 
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end()); // 숫자 크기 순으로 정렬

    // 최대공약수의 약수들을 출력
    int result =  differenceGcd(numbers);
    for (int i = 2; i <= result; ++i) {
        if (result % i == 0) {
            cout << i << " ";
        }
    }

    return 0;
}
