#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int v[1000], t[1000];
int v2[1000], t2[1000];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    vector<int> a_timeline;
    int a_pos = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i] >> t[i];
        for (int time = 0; time < t[i]; time++) {
            a_pos += v[i];
            a_timeline.push_back(a_pos);
        }
    }
    
    vector<int> b_timeline;
    int b_pos = 0;
    for (int i = 0; i < M; i++) {
        cin >> v2[i] >> t2[i];
        for (int time = 0; time < t2[i]; time++) {
            b_pos += v2[i];
            b_timeline.push_back(b_pos);
        }
    }

    int leader = 0; 
    int ans = 0;
    for (int time = 0; time < a_timeline.size(); time++) {

        int current_leader;
        if (a_timeline[time] > b_timeline[time]) {
            current_leader = 1;
        } 
        else if (b_timeline[time] > a_timeline[time]) {
            current_leader = 2;
        } 
        else {
            current_leader = 0;
        }

        if (current_leader != 0 && current_leader != leader) {
            ans++;
        }

        leader = current_leader;
    }

    cout << ans - 1 << '\n';
    
    return 0;
}
