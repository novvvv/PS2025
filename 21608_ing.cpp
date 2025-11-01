#include <iostream>
using namespace std;
int n;
int likes[21][5]; // 학생당 좋아하는 학생 4명의 번호
int board[21][21];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// stu_logic_1 비어있는 칸 중에서 "좋아하는 학생이 인접한 칸에 가장 많은 칸"으로 자리를 정한다
// @Param stu : 기준이되는 학생의 번호
// stu_x, stu_y : 학생이 배정될 교실의 좌석 인덱스
bool stu_logic_1(int stu) {
    
    int max_cnt = -1, stu_x = -1, stu_y = -1;
    vector<int> like_cnt;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            
            int cnt = 0;
            
            // 칸이 비어있음.
            if (board[x][y] == 0) {
                
                // 상하좌우 좋아하는 사람 배열 탐색
                int nx = x, ny = y;
                for (int dir = 0; dir < 4; dir++) {
                    
                    nx = x + dx[dir];
                    ny = y + dy[dir];
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    
                    for (int like = 0; like < 4; like++) {
                        if (likes[stu][like] == board[nx][ny]) cnt++;
                    }
                }
                
                if (max_cnt < cnt) {
                    like_cnt.push_back(cnt);
                    max_cnt = cnt;
                    stu_x = x;
                    stu_y = y;
                }
            }
            
        }
    }
    
    if (max_cnt != 0 && !like_cnt.size() == 1) {
        board[stu_x][stu_y] = stu; 
        return true; 
    }
    return false; 
}

// stu_logic_2 비어있는 칸이 가장 많은 칸
// @Param stu : 기준이되는 학생의 번호
bool stu_logic_2(int stu) {

    int max_cnt = -1, stu_x = -1, stu_y = -1;
    vector<int> empty_cnt;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            
            int cnt = 0;
            
            // 칸이 비어있음.
            if (board[x][y] == 0) {
                
                // 상하좌우 비어있는 칸 탐색 
                int nx = x, ny = y;
                for (int dir = 0; dir < 4; dir++) {
                    nx = x + dx[dir];
                    ny = y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (board[nx][ny] == 0) {
                        cnt++;
                    }
                }
                
                if (max_cnt < cnt) {
                    like_cnt.push_back(cnt);
                    max_cnt = cnt;
                    stu_x = x;
                    stu_y = y;
                }

            }
            
        }
    }
    
    if (max_cnt != 0 && !empty_cnt.size() == 1) {
        board[stu_x][stu_y] = stu; 
        return true; 
    }
    return false; 
}

int main() {
    
    cin.tie(0);
    cin >> n;
    
    // n^2의 줄에 학생의 번호, 학생이 좋아하는 학생 4명의 번호가 출력된다.
    for (int i = 0; i < n; i++) {

        cin >> likes[i][0]; // 학생 번호
        cin >> likes[i][1] >> likes[i][2] >> likes[i][3] >> likes[i][4];
        
        stu_logic_1(likes[i][0]); // #Logic1 : 좋아하는 학생이 가장 많은 칸
        stu_logic_2(likes[i][0]); // #Logic2 : 비어있는 칸이 가장 많은 칸 
        stu_logic_3(likes[i][0]); // #Logic3 : 행 번호 가장 적거나, 열 번호가 가장 적은 칸 
    }
    // 만족도 계산 공식 : 인접한 칸에 앉은 좋아하는 학생의 수
    
}

// n * n 크기 격자
// 학교에 다니는 학생 수 n^2
// 1번 ~ N^2번
// (r, c) r행 c열
// 각 학생이 좋아하는 학생 4명이 정해진다.

// 한 칸에는 학생 한 명의 자리만 있다. |r1 - r2| + |c1 - c2| = 1 - 인접한다.
// #1 비어있는 칸 중에서 "좋아하는 학생이 인접한 칸에 가장 많은 칸"으로 자리를 정한다 (?)
// #2 1을 만족하는 칸이 여러개면, 인접하는 칸 중에서 비어있는 칸이 가장 많은 자리로 정한다.
// #3 2를 만족하는 칸이 여러개면, 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러개면
// 열의 번호가 가장 작은 칸.

