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

bool check_univ(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return true; // 부모가 동일 -> 같은 집합
    return false; // 부모가 다르다. -> 다른 집합
}

int main () {

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    nodes.resize(n + 1, -1);
    
    for (int i = 0; i < m; i++) {
        int oper, a, b;
        cin >> oper >> a >> b;
        if (oper == 0) uni(a, b);
        else if (oper == 1) {
            if (check_univ(a, b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    
    // 합집합 연산, 두 원소가 같은 집합에 포함되어 있는지 확인
    
    return 0;
}

// 합집합 : 0, a, b (a가 포함되어 있는 집합과 b가 포함되어 있는 집합을 합친다.)
// 1, a, b : 두 원소가 같은 집합에 포함되어 있는가?
// -> 같은 집합에 포함되어 있다. : YES
// -> 같은 집합에 포함되어 있지 않다. : NO
