#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> tree[501];
int is_visit[501]; // 방문 체크, 깊이 체크
int tree_node = 0;

bool is_cycle = false;
void dfs(int cur_node, int parent) {
    
    
    is_visit[cur_node] = true; // 현재 노드 방문 처리
    
    // 연결된 노드를 모두 탐색
    for (int i = 0; i < tree[cur_node].size(); i++) {
        
        int nxt = tree[cur_node][i];

        // 방문하지 않은 노드라면 dfs 탐색
        if (!is_visit[nxt]) {
            dfs(nxt, cur_node);
        }
        

        // 다음 노드가 부모가 아닌데, 방문하려는 경우 -> 사이클
        else if (nxt != parent){
            is_cycle = true;
            return;
        }
        
    }
    
}

int main() {
    
    cin.tie(0);
    
    int n, m;
    int test_case = 1;
    while (true) {
        
        cin >> n >> m; // 정점의 개수 n, 간선의 개수 m
        if (n == 0 && m == 0)
            break;
        
        // Tree 기본 정보 초기화
        is_cycle = false;
        tree_node = 0;
        memset(is_visit, 0, sizeof(is_visit));
        for (int i = 0; i <= n; i++) vector<int>().swap(tree[i]);
        
        // 정점, 간선 정보 입력
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        // 메인 로직
        for (int i = 1; i <= n; i++) {
            if (tree[i].empty()) {
                tree_node++;
            }
            else if (!is_visit[i]){
                is_cycle = false;
                dfs(i, 0);
                if (!is_cycle)
                    tree_node++;
            }
        }
        
        if (tree_node == 0) {
            cout << "Case " << test_case << ": No trees." << '\n';
        }
        else if (tree_node == 1) {
            cout << "Case " << test_case << ": There is one tree." << '\n';
        }
        else {
            cout << "Case " << test_case << ": A forest of " << tree_node << " trees." << '\n';
        }
        test_case++;
    }
    
    
}

// 해당 문제의 조건
// 1. 연결 그래프
// 2. 사이클이 없다.

// is_visit[nxt] == 0 : 처음 방문
// is_visit[nxt] != 0 : 이미 방문
// is_visit[nxt] = is_visit[n] - 1 : 부모노드


