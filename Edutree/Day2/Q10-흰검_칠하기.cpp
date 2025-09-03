#include <iostream>

using namespace std;

int n;
int x[1000];
char dir[1000];

const int offset = 1000 * 100 + 5;
int white_cnt[200005] = {0, };
int black_cnt[200005] = {0, };
int last_color[200005] = {0, };

int main() {
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    int cur_pos = 0;
    int st_pos;
    
    for (int i = 0; i < n; i++) {
        
        // 우측이동 -> 검은색
        if (dir[i] == 'R') {
            st_pos = cur_pos; // st_pos : 시작위치
            cur_pos = (cur_pos + x[i] - 1); // 현재 위치를 기반으로 x[i] 만큰 칠함
            for (int j = st_pos; j <= cur_pos; j++) {
                int idx = j + offset;
                black_cnt[idx]++;
                last_color[idx] = 2;
            }
        }
        
        // 좌측이동 -> 흰색
        else {
            st_pos = cur_pos;
            cur_pos = cur_pos - x[i] + 1;
            for (int j = cur_pos; j <= st_pos; j++) {
                int idx = j + offset;
                white_cnt[idx]++;
                last_color[idx] = 1;
            }
        }
        
    }
    
    int white = 0, black = 0, grey = 0;
    for (int i = 0; i < 200001; i++) {
        if (white_cnt[i] >= 2 && black_cnt[i] >= 2) grey++;
        else if (last_color[i] == 1) white++;
        else if (last_color[i] == 2) black++;
    }
    
    cout << white << " " << black << " " << grey << '\n';
    

    return 0;
}

// N번의 명령에 걸쳐서 움직인다.
// x L 왼쪽으로 현재 이치 포함 x칸의 타일을 흰색으로 칠한다.
// x R 오른쪽을 이동하면서 현재 위치 포함 x칸의 타일을 검은색으로 칠한다.
// 흰색, 검은색으로 두 번 이상 칠해치면 회색
