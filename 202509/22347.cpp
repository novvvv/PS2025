#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int apple[301][301] = {0, };
int apple_sum[301][301] = {0, }; // 2d array prerfix_sum


int main () {

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, m; // n = row, m = column
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> apple[i][j];
        }
    }
    
    // 2차원 누적합 계산 로직
    // [Logic1] row(행) 방향으로 모든 원소의 합을 구한다.
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            // 이전 열까지의 합(apple_sum[y][x-1])에 현재 값을 더한다.
            apple_sum[y][x] = apple_sum[y][x-1] + apple[y][x];
        }
    }
    
    // [Logic2] Column(열) 방향으로 모든 원소의 합을 구한다.
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            // 이전 행까지의 합(apple_sum[y-1][x] + apple[y-1][x])에 현재 값을 더한다.
            apple_sum[y][x] = apple_sum[y-1][x] + apple_sum[y][x];
        }
    }
    
    int ans = 0;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            for (int y_idx = y; y_idx <= n; y_idx++) {
                for (int x_idx = x; x_idx <= m; x_idx++) {
                    int rect = apple_sum[y_idx][x_idx] - apple_sum[y-1][x_idx]
                                - apple_sum[y_idx][x-1] + apple_sum[y-1][x-1];

                    if (rect == 10) ans++;
                    if (rect > 10) break; // 가지치기
                }
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

// 2차원 누적합 점화식
// S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j]
