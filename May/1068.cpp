#include <iostream>
#include <vector>
using namespace std;

bool isVisit[51];
vector<int> adj_list[51];
int n; // 1st line :  트리의 노드 개수 n개
int root_node; // root node
int delete_node; // 제거할 노드
int leaf_node_cnt; // 리프노드 수

void dfs(int cur_node) {
    
    if (cur_node == delete_node) return;
    
    // node가 비어있다? -> 리프노드
    if (adj_list[cur_node].empty()) {
        leaf_node_cnt++;
        return;
    }
    
    for (int i = 0; i < adj_list[cur_node].size(); i++) {
        
        // Exception
        //  현재 노드에서 자식이 하나 있고, 자식이 삭제될 예정인 노드라면 "리프 노드로 간주"
        if ((adj_list[cur_node].size() == 1) && adj_list[cur_node][i] == delete_node) {
            leaf_node_cnt++;
        }
        else {
            dfs(adj_list[cur_node][i]);
        }
    }
    
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        // 노드의 부모가 주어진다?
        int node;
        cin >> node;
        if (node == -1)
            root_node = i;
        else {
            adj_list[node].push_back(i);
        }
    }

    cin >> delete_node;
    dfs(root_node);
    cout << leaf_node_cnt << endl;
    
    return 0;
}
