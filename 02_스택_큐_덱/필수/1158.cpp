#include <iostream>
#include <queue>

using namespace std;

void calculation(int n, int k) {
  queue<int> q;

  for(int i=1; i<=n; ++i) {
    q.push(i);
  }

  cout << "<";

  while (!q.empty()) { // k-1번째까지 숫자는 큐에서 빼고 다시 큐에 넣기 
    for (int i=0; i<k-1; ++i) {
      q.push(q.front());
      q.pop();
    }

    cout << q.front(); 
    q.pop(); // k번째 수를 결과에 추가하고 큐에서 제거하기 

    if (!q.empty()) {
      cout << ", ";
    }
  }

  cout << ">" << '\n'; 
}

int main() {
  int n,k;
  cin >> n >> k; 

  calculation(n, k);
  return 0;
}