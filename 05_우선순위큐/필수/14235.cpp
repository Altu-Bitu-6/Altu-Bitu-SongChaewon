#include <iostream>
#include <queue>

using namespace std;

void christmasGifts(int n) {
    priority_queue<int> pq;
    
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m; 
        
        if (m == 0) { // 선물을 꺼내는 경우
            if (pq.empty()) {
                cout << -1 << '\n'; // 선물이 없는 경우 -1 출력
            } else {
                cout << pq.top() << '\n'; // 가장 큰 선물 출력
                pq.pop(); // 가장 큰 선물 제거
            }
        } else {
            for (int j = 0; j < m; j++) {
                int gift;
                cin >> gift; // 선물의 가격 입력받기
                pq.push(gift); // 선물 큐에 추가
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n; 
    
    christmasGifts(n);
    
    return 0;
}
