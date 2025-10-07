#include <iostream>
#include <vector>
using namespace std; 

vector<int> nodes;
int cycle_num = 0; 

int find (int x) {
    if (nodes[x] < 0) return x; // 정점도달
    return nodes[x] = find(nodes[x]); // 부모 탐색 (경로 압축)
}

bool uni (int u, int v) {
    u = find(u); // u의 루트
    v = find(v); // v의 루트 
    if (u == v) {
        // 사이클 완성 
        return false;
    }
    nodes[v] = u;
    return true; 
}

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; 
    cin >> n >> m;
    nodes.resize(n+1, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; 
        if(!uni(u, v)) {
            cycle_num = i + 1;
            break;
        };     
    }
    cout << cycle_num << endl; 
}

// 선 플레이어가 홀수 번째 차례, 후 플레이어가 짝수 번째 차례 
// 평면상 n개의 정점, 어느 세 점도 일직선 위에 놓이지 않는다. 
// 매 차례 마다 플레이어는 두 점을 선택해 이를 연결하는 선분을 긋는다. 
// 입력으로 정점(n)과 m번째 차례까지 게임 진행 상항이 주어지며, 사이클이 완성 되었는지를 판단,
// 완성 되었다면 몇 번째 차례에서 사이클이 완성 되었는지 출력하시오 
