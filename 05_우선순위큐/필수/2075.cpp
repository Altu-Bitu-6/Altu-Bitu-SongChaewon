#include <iostream>
#include <queue>

using namespace std;

// N번째 큰 수를 찾는 함수
int findNthLargest(int N) {
    priority_queue<int, vector<int>, greater<int>> pq; // 우선순위 큐 사용

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        pq.push(num);
    }
    
    // 큐의 크기를 유지하며 새로운 숫자 삽입
    for (int i = N; i < N * N; ++i) {
        int num;
        cin >> num;
        
        if (num > pq.top()) { // 새로운 숫자가 현재 큐의 최솟값보다 크면
            pq.pop(); // 최솟값을 제거하고
            pq.push(num); // 새로운 숫자를 삽입
        }
    }
    
    return pq.top(); // 우선순위 큐의 top에는 N번째 큰 수가 위치함
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    cout << findNthLargest(N) << '\n';
    
    return 0;
}
