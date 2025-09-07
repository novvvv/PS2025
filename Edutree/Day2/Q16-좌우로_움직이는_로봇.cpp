#include <iostream>
#include <vector> 
using namespace std;

int n, m;
int t[50000]; // A가 움직인 시간
char d[50000]; // A가 움직인 방향
int t_b[50000]; // B가 움직인 시간
char d_b[50000]; // B가 움직인 방향

int main() {

    cin.tie(0);

    cin >> n >> m;

    // d는 L 또는 R 고정 
    vector<int> a_timeline;
    int a_time = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> d[i];
        if (d[i] == 'L') {
            for (int time = 0; time < t[i]; time++) {
                a_time--;
                a_timeline.push_back(a_time);
            }
        }
        else {
            for (int time = 0; time < t[i]; time++) {
                a_time++;
                a_timeline.push_back(a_time);
            }
        }
    }

    vector<int> b_timeline;
    int b_time = 0; 
    for (int i = 0; i < m; i++) {
        cin >> t_b[i] >> d_b[i];
        if (d_b[i] == 'L') {
            for (int time = 0; time < t_b[i]; time++) {
                b_time--;
                b_timeline.push_back(b_time);
            }
        }
        else {
            for (int time = 0; time < t_b[i]; time++) {
                b_time++;
                b_timeline.push_back(b_time);
            }
        }
    }

    int total_time = (a_timeline.size() < b_timeline.size()) ? b_timeline.size() : a_timeline.size(); 
    a_timeline.insert(a_timeline.begin(), 0);
    b_timeline.insert(b_timeline.begin(), 0);


    // 움직임이 끝난 로봇은 해당 위치에 머무른다. 
    while (a_timeline.size() <= total_time) {
        a_timeline.push_back(a_timeline.back());
    }
    while (b_timeline.size() <= total_time) {
        b_timeline.push_back(b_timeline.back());
    }

    int ans = 0;
    for (int t = 1; t < total_time; t++) {
        if (a_timeline[t] == b_timeline[t] && a_timeline[t-1] != b_timeline[t-1]) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
