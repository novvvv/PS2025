#include <iostream>
#include <deque>
#include <climits> 
using namespace std;

int n;
int a[1003];

int cal_dis(deque<int> room) {
    int dis_sum = 0, cnt = 1;
    for (int i = 1; i < room.size(); i++) {
        dis_sum += room[i] * cnt;
        cnt++;
    }
    return dis_sum;
}

deque<int> rotate_room(deque<int> room) {
    room.push_back(room.front());
    room.pop_front();
    return room;
}

int main() {
    cin >> n;
    deque<int> room;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        room.push_back(a[i]);
    }

    long long min_dis = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        int dis = 0;
        dis += cal_dis(room);
        if (dis < min_dis) min_dis = dis;
        room = rotate_room(room);
    }

    cout << min_dis << '\n';

    return 0;
}
