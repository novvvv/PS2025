#include <iostream>

using namespace std;

int N;
int A[100];

int main() {
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if ((A[i] <= A[j]) && (A[j] <= A[k])) {
                    ans++;
                }
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}

// N마리의 소가 x = 1 부터 x = N까지 순서대로 서 있다.
