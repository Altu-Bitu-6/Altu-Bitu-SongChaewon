#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int similar(const vector<string>& words) {
    int count = 0;

    multiset<char> baseSet(words[0].begin(), words[0].end()); // 첫 번째 단어의 문자로 이루어진 multiset 생성

    for (int i = 1; i < words.size(); ++i) {
        multiset<char> currentSet(words[i].begin(), words[i].end()); // i번째 단어의 문자로 이루어진 multiset 생성

        multiset<char> diffSet1, diffSet2; 
        set_difference(baseSet.begin(), baseSet.end(), currentSet.begin(), currentSet.end(), inserter(diffSet1, diffSet1.begin()));
        set_difference(currentSet.begin(), currentSet.end(), baseSet.begin(), baseSet.end(), inserter(diffSet2, diffSet2.begin()));

        if (diffSet1.size() <= 1 && diffSet2.size() <= 1) {
            ++count;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    int similarWords = similar(words); 

    cout << similarWords << '\n';

    return 0;
}
