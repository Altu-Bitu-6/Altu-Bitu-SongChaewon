#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;
vector<bool> prime(MAX+1, true); // 인덱스 0부터 1000000까지 사용

void sieve() { // 시간초과 문제 해결을 위해 에라토스테네스의 체를 이용하여 소수 판별하기
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= MAX; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    sieve(); 

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break; // 입력이 0일 경우 종료
        }

        bool found = false;
        for (int i = 3; i <= n / 2; i += 2) {
            if (prime[i] && prime[n - i]) {
                cout << n << " = " << i << " + " << n - i << '\n';
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }

    return 0;
}
