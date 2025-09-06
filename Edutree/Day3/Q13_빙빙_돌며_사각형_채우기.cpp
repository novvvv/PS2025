#include <iostream>

using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char board[101][101] = {0, }; 
int dir = 0;

bool in_range(int x, int y) {
    return ((0 <= x) && (x < n) && (0 <= y) && (y < m));
}

int main() {

    cin >> n >> m;
    int x = 0, y = 0;
    char cur_alpha = 'A';
    board[x][y] = cur_alpha;

    for (int i = 2; i <= n * m; i++) {

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!(in_range(nx, ny)) || !(board[nx][ny] == 0)) {
            dir = (dir + 1) % 4;
        }

        x = x + dx[dir];
        y = y + dy[dir];

        if (cur_alpha == 'Z') {
            cur_alpha = 'A';
        }
        else {
            cur_alpha = cur_alpha + 1;
        }
        
        board[x][y] = cur_alpha;

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
