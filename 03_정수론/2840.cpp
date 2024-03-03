#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 함수의 용도: 행운의 바퀴를 시뮬레이션하여 결과를 출력
void luckyWheel() {
    int N, K;
    cin >> N >> K;
    
    // 바퀴 초기화
    vector<char> pan(N, '?');
    
    int index = 0;
    
    for (int i = 0; i < K; i++) {
        int count; 
        char tmpc;
        cin >> count >> tmpc;
        
        // 처음 입력일 경우
        if (i == 0) {
            pan[0] = tmpc; 
            index = 0; 
            continue;
        }
        
        // 바퀴를 돌리기
        index = (count + index) % N;
        
        // 돌렸을 때 같은 문자(같은 자리)는 나올 수 있다.
        // 그것마저 아니면 틀린 원판
        if (pan[index] != '?' && pan[index] != tmpc) { 
            cout << "!";
            return;
        } else {
            pan[index] = tmpc;
        }
    }
    
    // 중복 체크
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (pan[i] != '?' && pan[i] == pan[j]) { 
                cout << "!";
                return;
            }
        }
    }
    
    // 바퀴의 상태 출력
    for (int i = 0; i < N; i++) {
        cout << pan[index];
        index--;
        if (index == -1) index = N - 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    luckyWheel();

    return 0;
}
