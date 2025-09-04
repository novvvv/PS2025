#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // abs
using namespace std;

int n;
int A[100];
vector<int> ans;

int main() {
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < n; i++) {
        int target = A[i];
        int cost = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            cost += abs(i - j) * A[j];
        }
        ans.push_back(cost);
    }
    
    cout << *min_element(ans.begin(), ans.end()) << '\n';

    return 0;
}

// x = 1 ~ x = N Ai명의 사람이 살고있다.
// 회의를 위해서 N개의 집 중 한곳에 전부 모인다.
// 모든 사람들의 이동 거리의 합이 최소가 된다.
