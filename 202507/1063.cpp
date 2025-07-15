#include <iostream>
#include <string>
using namespace std;

// BOJ 1063

// 좌표 배열
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main () {

    // 킹의 위치, 돌의 위치, 움직이는 횟수
    string king_pos, rock_pos;
    int cnt;
    cin >> king_pos >> rock_pos >> cnt;

    int king_pos_X = king_pos[0] - 'A';
    int king_pos_Y = king_pos[1] - '1';
    int rock_pos_X = rock_pos[0] - 'A';
    int rock_pos_Y = rock_pos[1] - '1';

    int direction = 0;
    for (int i = 0; i < cnt; i++) {
        
        string cmd;
        cin >> cmd;
        
        
        if (cmd == "T") direction = 0;
        else if (cmd == "RT") direction = 1;
        else if (cmd == "R") direction = 2;
        else if (cmd == "RB") direction = 3;
        else if (cmd == "B") direction = 4;
        else if (cmd == "LB") direction = 5;
        else if (cmd == "L") direction = 6;
        else if (cmd == "LT") direction = 7;

        int nxt_king_pos_X = king_pos_X + dx[direction];
        int nxt_king_pos_Y = king_pos_Y + dy[direction];
    

        if (nxt_king_pos_X < 0 || nxt_king_pos_X >= 8 || nxt_king_pos_Y < 0 || nxt_king_pos_Y >= 8)
            continue;
        
        // 킹이 가려는 위치에 돌이 존재하는 경우
        if (nxt_king_pos_X == rock_pos_X && nxt_king_pos_Y == rock_pos_Y) {
            
            int nxt_rock_pos_X = rock_pos_X + dx[direction];
            int nxt_rock_pos_Y = rock_pos_Y + dy[direction];
            
            // Exception : 돌이 체스판 밖으로 나간 경우
            if (nxt_rock_pos_X < 0 || nxt_rock_pos_X >= 8 || nxt_rock_pos_Y < 0 || nxt_rock_pos_Y >= 8)
                continue;
            
            // 돌 이동
            rock_pos_X = nxt_rock_pos_X;
            rock_pos_Y = nxt_rock_pos_Y;
        }

        // 킹 이동
        king_pos_X = nxt_king_pos_X;
        king_pos_Y = nxt_king_pos_Y;
        
    }

    cout << (char)(king_pos_X + 'A') << (char)(king_pos_Y + '1') << '\n';
    cout << (char)(rock_pos_X + 'A') << (char)(rock_pos_Y + '1') << '\n';

}
