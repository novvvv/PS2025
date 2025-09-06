#include <iostream>

using namespace std;

int n;
int grid[100][100];
int dir = 0;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool in_range(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

int main() {

    cin >> n;
    int x = n / 2, y = n / 2;
    int move_cnt = 0;
    grid[x][y] = 1;
    int move_length = 1;
    int num = 2; 
    while(num <= n * n) {
        
        for (int len = 0; len < move_length; len++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            x = x + dx[dir];
            y = y + dy[dir];

            grid[x][y] = num;
            num++;
        }

        dir = (dir + 1) % 4;
        move_cnt++;
        if (move_cnt == 2) {
            move_length++;
            move_cnt = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

    
    return 0;
}
