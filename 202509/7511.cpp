#include <iostream>
#include <vector>
using namespace std;

vector<int> nodes;

int find(int u) {
    if (nodes[u] < 0)
        return u;
    return nodes[u] = find(nodes[u]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    nodes[v] = u;
    return true;
}

bool chk_uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return true;
    return false;
}

int main () {

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        
        // n : 유저의 수 (100000), k : 친구 관계의 수 (10000)
        // 유저 3명, 친구 관계의 수 1개
        int n, k;
        cin >> n >> k;
        
        nodes.assign(n+1,-1);
        
        for (int j = 0; j < k; j++) {
            int u, v;
            cin >> u >> v;
            uni(u, v);
        }
        
        
        // 0 <= a, b < n ... 유저 a, b는 친구다
        // 미리 구할 쌍의 수 1 <= m <= 10^5
        // 구해야 하는 쌍 u, v
        
        int m;
        cin >> m;
        cout << "Scenario " << i + 1 << ":" << '\n';
        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            // 두 사람 사이에 경로가 존재한다. (부모가 같다)
            if (chk_uni(u, v)) {
                cout << 1 << '\n';
            }
            // 두 사람 사이에 경로가 존재하지 않는다. (부모가 다르다)
            else {
                cout << 0 << '\n';
            }
        }
        cout << '\n';
        
    }

    
    return 0;
}


// 친구 관계 그래프를 그린다.
// 두 사람 사이의 친구 관계 그래프상에서 경로가 주어지는가
