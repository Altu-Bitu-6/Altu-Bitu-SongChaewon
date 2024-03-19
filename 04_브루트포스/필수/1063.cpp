#include <iostream>
#include <string>
#include <map>

using namespace std;

// 방향에 따른 이동 값을 저장
map<string, pair<int, int>> MOVE_DIRECTION = { 
    {"R", {0, 1}}, {"L", {0, -1}},
    {"B", {-1, 0}}, {"T", {1, 0}},
    {"RT", {1, 1}}, {"LT", {1, -1}},
    {"RB", {-1, 1}}, {"LB", {-1, -1}}
};

// 체스판 위의 위치를 좌표로 변환
pair<int, int> positionToCoordinate(string position) {
    return {position[1] - '1', position[0] - 'A'};
}

// 좌표를 체스판 위의 위치로 변환
string coordinateToPosition(pair<int, int> coordinate) {
    return string(1, 'A' + coordinate.second) + to_string(coordinate.first + 1);
}

// 주어진 이동이 체스판 내로 이루어지는지 확인
bool isValidMove(int row, int col) {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

int main() {
    string king_position, stone_position, move;
    int n;
    cin >> king_position >> stone_position >> n;

    // 킹과 돌의 초기 위치를 좌표로 변환
    pair<int, int> king = positionToCoordinate(king_position);
    pair<int, int> stone = positionToCoordinate(stone_position);

    while (n--) {
        cin >> move;
        pair<int, int> direction = MOVE_DIRECTION[move];
        pair<int, int> next_king = {king.first + direction.first, king.second + direction.second};

        if (isValidMove(next_king.first, next_king.second)) {
            // 킹의 다음 위치가 돌의 위치와 같다면
            if (next_king == stone) {
                pair<int, int> next_stone = {stone.first + direction.first, stone.second + direction.second};
                // 돌이 체스판을 벗어나지 않는다면 함께 이동
                if (isValidMove(next_stone.first, next_stone.second)) {
                    king = next_king;
                    stone = next_stone;
                }
            } else {
                // 킹만 이동
                king = next_king;
            }
        }
    }

    cout << coordinateToPosition(king) << '\n' << coordinateToPosition(stone) << '\n';

    return 0;
}
