#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main () {

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<long long> containers(n);
    
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> containers[i];
        total_sum += containers[i];
    }
    
    // Logic1 최종 목표 높이 계산
    // 높이는 q 혹은 q + 1 이어야 한다.
    // total_sum = 9 , n = 4 , q = 2 , r = 1
    // 즉 n - r 개는 기준 높이 (q) 를 가지고
    // r개는 기준 높이 (q+1) 를 가진다.
    long long q = total_sum / n; // 기준 높이
    long long r = total_sum % n; // (q + 1) 높이가 되어야 할 칸의 개수
    
    sort(containers.begin(), containers.end()); // 1 2 3 3
    
    // Logic2
    long long moves = 0;
    for(int i = 0; i < n; i++) {
        
        long long target_height;
        // 키가 작은 n-r개는 q를 목표로, 키가 큰 r개는 q+1을 목표로 함
        if (i < n - r) {
            target_height = q;
        } else {
            target_height = q + 1;
        }
        
        // 원래 가진 게 목표보다 많으면, 그 차이만큼이 옮겨야 할 양
        if (containers[i] > target_height) {
            moves += containers[i] - target_height;
        }
    }
    
    // 채워야 할 양의 총합 = 넘치는 양의 총합
    
    cout << moves << endl;
    
    return 0;
}
