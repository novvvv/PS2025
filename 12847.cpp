#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> days(n);
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }
    

    // [Exception] 윈도우 크기 >= 배열 크기
    if (m >= n) {
        cout << accumulate(days.begin(), days.end(), 0LL) << '\n';
        return 0;
    }
    
    // [Exception] 윈도우 크기 = 0
    if (m == 0) {
        cout << 0 << '\n';
        return 0;
    }
    
    long long sliding_window = 0;
    for (int i = 0; i < m; i++) {
        sliding_window += days[i];
    }
    
    long long max_window = sliding_window;
    
    for (int i = m; i < n; i++) {
        sliding_window = sliding_window + days[i] - days[i-m];
        max_window = max(max_window, sliding_window);
    }
    
    cout << max_window << '\n';
    
     
}
