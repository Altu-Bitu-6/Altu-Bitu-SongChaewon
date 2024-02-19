#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> fashionMap;

int countFashionCombinations() {
    int result = 1;

    for (const auto& pair : fashionMap) {
        result *= (pair.second + 1); // 아이템을 선택하지 않는 경우에 +1
    }

    return result - 1; // 모든 종류에서 아무 아이템도 선택하지 않는 경우에 -1
}

int main() {
    int T; 
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int n; 
        cin >> n;

        fashionMap.clear();

        for (int j = 0; j < n; ++j) {
            string name, type;
            cin >> name >> type;

            if (fashionMap.find(type) == fashionMap.end()) {
                fashionMap[type] = 1;
            } else {
                fashionMap[type]++;
            }
        }
        cout << countFashionCombinations() << endl;
    }

    return 0;
}
