#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    // 입출력 속도 향상 (대량의 M 처리)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n); // 천만
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int x;
    cin >> x;
    
    sort(v.begin(), v.end());
    int l_ptr = 0, r_ptr = n - 1, cnt = 0;
    
    while (l_ptr < r_ptr) {
        int target = v[l_ptr] + v[r_ptr];
        if (target == x) {
            cnt++;
            l_ptr++;
            r_ptr--;
        }
        else if (target < x) l_ptr++;
        else r_ptr--;
    }
    
    cout << cnt << endl;
    
}
