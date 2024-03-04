#include <iostream>

using namespace std;

int god(int a, int b) { // 최대공약수 구하는 함수 
  while(b != 0) {
    int temp = b;
    b = a % b;
    a = temp; 
  }
  return a; 
}

pair<int, int> addFraction(int num1, int den1, int num2, int den2) { // 두 분수를 더하는 함수
  // num1,2: 분자, den1,2: 분모 
  int result_num = num1 * den2 + num2 * den1; 
  int result_den = den1 * den2;

  int common_factor = god(result_num, result_den); // 분자, 분모의 공통 인수는 두 수의 최대 공약수 
  result_num /= common_factor;
  result_den /= common_factor;

  return make_pair(result_num, result_den);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL); 

  int num1, den1, num2, den2;
  cin >> num1 >> den1 >> num2 >> den2;

  pair<int, int> result = addFraction(num1, den1, num2, den2);
  cout << result.first << ' ' <<result.second << '\n';

  return 0;
}
