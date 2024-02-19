#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {

    int n, m;
    int count = 0;

    unordered_set<string> strings;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        string set;
        cin >> set;
        strings.insert(set); 
    }

    for (int i = 0; i < m; ++i) {
        string set;
        cin >> set;

        if (strings.find(set) != strings.end()) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
