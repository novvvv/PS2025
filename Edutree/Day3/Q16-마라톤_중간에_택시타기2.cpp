#include <iostream>
#include <vector> 
#include <utility> 
using namespace std;

int n;
int x[100];
int y[100];

vector<pair<int, int>> marathon;
int cal_distance(vector<pair<int, int>> vec) {
    int distance_sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1) continue;
        distance_sum += abs(vec[i].first - vec[i+1].first) + abs(vec[i].second - vec[i+1].second);
    }
    return distance_sum;
}


int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        marathon.push_back(make_pair(x[i], y[i]));
    }

    int min_distance = 100000000; 
    
    for (int i = 1; i < n; i++) {
        vector<pair<int, int>> copy_marathon = marathon;
        copy_marathon.erase(copy_marathon.begin() + i);
        int dis = cal_distance(copy_marathon);
        if (dis < min_distance) min_distance = dis;
    }

    cout << min_distance << '\n';

    return 0;
}

// N개의 체크포인트
// 1번 체크포인트 시작 ~ 모든 체크포인트 방문 ~ N번 체크포인트 끝 
// 1개는 건너뛰고, (1번,N번) 두 개의 체크포인트는 건너 뛰지 않는다. 
// 1개를 건너 뛰었을때 최소거리는? 
