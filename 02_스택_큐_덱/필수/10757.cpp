#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addNumber(const string& num1, const string& num2) {
    string result;
    int carry = 0; // 올림을 저장

    int maxLength = max(num1.length(), num2.length()); 

    for (int i = 0; i < maxLength || carry; ++i) {
        int digit1 = i < num1.length() ? num1[num1.length() - i - 1] - '0' : 0; // 자릿수 없으면 0 
        int digit2 = i < num2.length() ? num2[num2.length() - i - 1] - '0' : 0;

        int sum = digit1 + digit2 + carry; 
        carry = sum / 10; // 다음 자리로 올림 
        result += (sum % 10) + '0'; 
    }

    reverse(result.begin(), result.end()); // 문자열 뒤집어서 반환
    return result;
}

int main() {

    string num1, num2;
    cin >> num1 >> num2;

    string result = addNumber(num1, num2);
    cout << result << '\n';

    return 0;
}
