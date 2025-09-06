#include <iostream>
#include <string>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

string commands;

int main() {

    cin >> commands;
    int dir = 0;
    int cur_x = 0, cur_y = 0; 
    int total_time = 0;
    bool flag = false; 
    for (int i = 0; i < commands.length(); i++) {

        if (flag) break;

        if (commands[i] == 'F') {
            cur_x += dx[dir];
            cur_y += dy[dir];
            total_time++;
            if ((cur_x == 0) && (cur_y == 0)) {
                flag = true; 
                break; 
            }
        }

        else if (commands[i] == 'R') {
            dir = (dir + 1) % 4;
            total_time++;
        }

        else if (commands[i] == 'L') {
            dir = (dir - 1 + 4) % 4;
            total_time++;
        }
    }

    if (flag) cout << total_time << '\n';
    else cout << -1 << '\n';

    return 0;
}

// (0, 0) 에서 북쪽을 향한 상태에서 움직인다. 
// N개의 명령. 
// L : 왼쪽 90도 방향전환 
// R : 오른쪽 90도 방향전환 
// F : 바라보고 있는 방향으로 한칸ㅇ ㅣ동 
// 회전에도 1초가 걸린다고 가정 시, 몇 초뒤에 처음으로 돌아오는가 
