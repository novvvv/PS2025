#include <iostream>

using namespace std;

int n, t;
int r, c;
char d;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int board[51][51] = {0, };

int main() {

    cin >> n >> t;
    cin >> r >> c >> d;

    // r, c (r행 c열)
    // d (U, D, R, L) (위, 아래, 오른쪽, 왼쪽)
    int cur_x = r, cur_y = c; 
    while (t--) {
        if (d == 'L') {
            if (cur_y == 1) {
                d = 'R'; 
                // cout << "[debug] : " << "cur_time : " << t << " " << cur_x << " " << cur_y << '\n';
                continue;
            }
            cur_y--;
            // cout << "[debug] : " << "cur_time : " << t << " " << cur_x << " " << cur_y << '\n';
        }
        else if (d == 'R') {
            if (cur_y == n) {
                d = 'L';
                // cout << "[debug] : " << "cur_time : " << t << " " << cur_x << " " << cur_y << '\n';
                continue;
            }
            cur_y++;
            // cout << "[debug] : " << "cur_time : " << t << " " << cur_x << " " << cur_y << '\n';
        }
        else if (d == 'U') {
            if (cur_x == 1) {
                d = 'D';
                // cout << "[debug] : " << "cur_time : " << t << " " << cur_x << " " << cur_y << '\n';
                continue;
            }
            cur_x--;
            // cout << "[debug] : " << "cur_time : " << t << " " << cur_x << " " << cur_y << '\n';
        }
        else if (d == 'D') {
            if (cur_x == n) {
                d = 'U';
                // cout << "[debug] : " << "cur_time : " << t << " " << cur_x << " " << cur_y << '\n';
                continue;
            }
            cur_x++;
            // cout << "[debug] : " << "cur_time : " << t << " " << cur_x << " " << cur_y << '\n';
        }
    }

    cout << cur_x << " " << cur_y << '\n';

    return 0;
}

// 방향을 바꾸는데 1만큼의 시간이 소요된다. 
