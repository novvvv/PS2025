#include <iostream>

using namespace std;

int n;
int numbers[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // n = 6
    // idx.  0 1 2 3 4 5 
    // value 2 1 6 2 7 8
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0; 
        if (i >= n - 2) continue; 
        for (int j = i + 2; j < n; j++) {
            sum = numbers[i] + numbers[j];
            max_val = max_val < sum ? sum : max_val;
            sum = 0;
        }
    }

    cout << max_val << '\n';

    return 0;
}
