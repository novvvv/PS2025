#include <iostream>

using namespace std;

int N, M;
int r[10000], c[10000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[101][101] = {0, };

int main() {
    
    cin >> N >> M;

    for (int i = 0; i < M; i++) {

        cin >> r[i] >> c[i];

        board[r[i]][c[i]] = 1; 
        int cnt = 0;
        for (int dir = 0; dir < 4; dir++) {
            int nx = r[i] + dx[dir];
            int ny = c[i] + dy[dir];
            if (board[nx][ny] == 1) cnt++;
        }

        if (cnt == 3) {
            cout << 1 << '\n';
        }
        
        else {
            cout << 0 << '\n';
        }
    }

    // n * n 크기의 격좌에 총 M번에 걸쳐 색칠을 칠한다.
    // "편안한 상태"에 놓여있는지 확인 
    // 편안한 상태를 지금 칠해진 칸을 기점으로 상하좌우 4칸중 3칸이 칠해져 있는가 

    return 0;
}
