#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; 
    cin >> n >> k; // 얼음 양동이 개수 (1 <= n <= 100000), 좌우로 K (1 <= K <= 2,000,000)  
    int max_point = 1000000;
    vector<int> points(1000000+1, 0); // 얼음 양동이가 놓여있는 좌표 x (0 <= x <= 1,000,000)

    // 양동이의 얼음 양 g, 양동이의 좌표 x
    int g, x; 
    for (int i = 0; i < n; i++) {
        cin >> g >> x;
        points[x] = g; 
    }

    int window_size = 2 * k + 1; 
    long long current_sum = 0;
    long long max_sum = 0; 

    // [Execption]
    // 윈도우의 크기가 전체 좌표계보다 큰 경우 -> 모든 얼음의 합
    if (window_size > 1000001) {
        for (int i = 0; i <= max_point; i++) {
            current_sum += points[i];
        }
        max_sum = current_sum; 
        cout << max_sum << '\n';
        return 0;
    }

    else {
        // 1. 윈도우 (0 ~ window-size-1) 범위의 합을 계산
        for (int i = 0; i < window_size; i++) {
            current_sum += points[i];
        } 
        max_sum = current_sum; 

        for (int i = window_size; i <= max_point; i++) {
            current_sum = current_sum + points[i] - points[i-window_size];
            max_sum = max(max_sum, current_sum);
        }
    }

    cout << max_sum << '\n';
    
}
