#include <iostream>

using namespace std;

int n;
int grid[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            int cur_x = j;
            int cur_y = i;
            int cnt = 0;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur_x + dx[dir];
                int ny = cur_y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                    continue;
                }
                if (grid[nx][ny] == 1) cnt++;
            }
            
            if (cnt >= 3) {
                ans++;
            }
            
        }
    }
    
    cout << ans << '\n';

    return 0;
}
