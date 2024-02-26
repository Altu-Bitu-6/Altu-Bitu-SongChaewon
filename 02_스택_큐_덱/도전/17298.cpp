#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> findBig(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // 초기화
    stack<int> st; // 인덱스 저장하는 스택

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            result[st.top()] = arr[i]; // 해당 인덱스의 결과를 현재 원소로 설정
            st.pop(); // 해당 인덱스를 스택에서 제거
        }

        st.push(i); // 현재 원소의 인덱스를 스택에 추가
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = findBig(arr);

    for (int i = 0; i < n; ++i) {
        cout << result[i] << ' ';
    }

    cout << '\n';

    return 0;
}
