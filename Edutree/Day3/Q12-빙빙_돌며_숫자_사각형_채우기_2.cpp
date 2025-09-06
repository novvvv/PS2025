#include <iostream>

using namespace std;

int n, m;
int board[101][101] = {0, };

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool in_range(int x, int y) {
    return ((0 <= x) && (x < n) && (0 <= y) && (y < m));
}

int main() {

    cin >> n >> m;
    int dir = 0;
    int x = 0, y = 0;
    board[x][y] = 1;
    for (int i = 2; i <= n * m; i++) {

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!(in_range(nx, ny)) || ((board[nx][ny]) != 0)) 
            dir = (dir + 1) % 4;
        
        x = x + dx[dir]; 
        y = y + dy[dir]; 
        board[x][y] = i; 

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
