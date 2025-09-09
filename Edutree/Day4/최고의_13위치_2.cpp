#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int arr[21][21];

int main() {

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) 
            cin >> arr[i][j];

    int max_num = -1, area_sum_1 = 0, area_sum_2 = 0;
    for (int r1 = 1; r1 <= N; r1++) {
        for (int c1 = 1; c1 <= N - 2; c1++) {

            for (int r2 = 1; r2 <= N; r2++) {
                for (int c2 = 1; c2 <= N - 2; c2++) {

                    // Exception : 행이 동일하고, 열의 거리가 3미만인경우?
                    if ((r1 == r2) && abs(c1 - c2) < 3) {
                        continue;
                    }

                    area_sum_1 = arr[r1][c1] + arr[r1][c1+1] + arr[r1][c1+2];
                    area_sum_2 = arr[r2][c2] + arr[r2][c2+1] + arr[r2][c2+2];
                    max_num = max(max_num, area_sum_1 + area_sum_2);

                }
            }
            
        }        
    }

    cout << max_num << '\n';

    return 0;
}
