#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x[100];
char dir[100];

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    const int OFFSET = 1000; 
    const int max_size = OFFSET * 2 + 1; 
    int visit_area[max_size] = {0, }; 
    int cur_pos = 0;

    for (int i = 0; i < n; i++) {

        cin >> x[i] >> dir[i];
        int st_pos = cur_pos; 
        if (dir[i] == 'R') {
            cur_pos += x[i];
        } 
        else {
            cur_pos -= x[i];
        }
        int ed_pos = cur_pos;

        // 오른쪽으로 이동한 경우 
        if (st_pos < ed_pos) {
            for (int j = st_pos; j < ed_pos; j++) {
                visit_area[j + OFFSET]++;
            }
        }
        // 왼쪽으로 이동한 경우
        else {
            for (int j = ed_pos; j < st_pos; j++) {
                visit_area[j + OFFSET]++;
            }
        }

    }

    int area = 0;
    for (int i = 0; i < max_size; i++) {
        if (visit_area[i] >= 2) area++;
    }
    cout << area << endl;

    return 0;
}

// N번의 명령 이후 2번 이상 지나간 영역의 크기
