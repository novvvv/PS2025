#include <iostream>

using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    int max_overlap = 0;
    for (int i = 0; i < n; i++) {
        int current_overlap = 0;
        int test_point = x1[i]; // 선분의 시작점
        for (int j = 0; j < n; j++) {
            if (x1[j] <= test_point && test_point <= x2[j]) {
                current_overlap++;
            }
        }
        if (max_overlap <= current_overlap) {
            max_overlap = current_overlap;
        }
    }

    cout << max_overlap << '\n';

    return 0;
}
