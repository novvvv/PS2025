#include <iostream>

using namespace std;

int N;
char dir[100];
int dist[100];

int dx[4] = {-1, 0 , 1, 0};
int dy[4] = {0, 1, 0, -1};

int board[101][101] = {0, };

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> dir[i] >> dist[i];
    }
    
    int cur_x = 0, cur_y = 0;
    int time_sum = 0;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (flag) break;
        if (dir[i] == 'N') {
            for (int time = 0; time < dist[i]; time++) {
                cur_x += dx[1];
                cur_y += dy[1];
                time_sum++;
                // cout << "[Debug] " << " cur_x : " << cur_x << "cur_y : " << cur_y << " time : " << time_sum << '\n';
                if ((cur_x == 0) && (cur_y == 0)) {
                    flag = true;
                    // cout << "[Debug] " << "탐색 성공" << time_sum << '\n';
                    break;
                }
            }
        } // x = 0, y = 1
        else if (dir[i] == 'E') {
            for (int time = 0; time < dist[i]; time++) {
                cur_x += dx[2];
                cur_y += dy[2];
                time_sum++;
                // cout << "[Debug] " << " cur_x : " << cur_x << "cur_y : " << cur_y << " time : " << time_sum << '\n';
                if ((cur_x == 0) && (cur_y == 0)) {
                    flag = true;
                    break;
                }
            }
        } // x = 1, y = 0;
        else if (dir[i] == 'S') {
            for (int time = 0; time < dist[i]; time++) {
                cur_x += dx[3];
                cur_y += dy[3];
                time_sum++;
                // cout << "[Debug] " << " cur_x : " << cur_x << "cur_y : " << cur_y << " time : " << time_sum << '\n';
                if ((cur_x == 0) && (cur_y == 0)) {
                    flag = true;
                    break;
                }
            }
        } // x = 0, y = -1
        else if (dir[i] == 'W') {
            for (int time = 0; time < dist[i]; time++) {
                cur_x += dx[0];
                cur_y += dy[0];
                time_sum++;
                // cout << "[Debug] " << " cur_x : " << cur_x << "cur_y : " << cur_y << " time : " << time_sum << '\n';
                if ((cur_x == 0) && (cur_y == 0)) {
                    flag = true;
                    break;
                }
            }
        }
    }
    
    if (flag) {
        cout << time_sum << '\n';
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}

// N번에 걸쳐서 움직이려는 방향과, 움직일 거리가 주어진다.
// 1초에 한 칸씩 움직인다.
// 몇 초뒤에 다시 (0, 0)으로 돌아오는가?
