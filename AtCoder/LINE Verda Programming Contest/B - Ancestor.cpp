#include <iostream>
using namespace std;


int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int arr[51];
    for (int i = 2; i <= n; i++) {
        cin >> arr[i];
    }
    
    int cnt = 1;
    int cur_idx = arr[n];
    while(true){
        if(cur_idx == 1) break;
        cur_idx = arr[cur_idx];
        cnt++;
    }
    cout << cnt << '\n';
    
}

// n명의 사람이 있다. n명의 사람에는 1번~n번 까지의 번호가 붙어있다.
// i번째 사람 (2<=i<=N) 의 부모는 Pi다
// Pi는 i보다 작음이 보장된다.
// 3번째 사람의 부모는 P3이며 P3는 3보다 작음이 보장된다.
// 1번째 사람은 N번째 사람의 몇대 전의 사람인지 구하시오

// 3 .. 1 2
// P2 = 1 (2번의 부모는 1번)
// P3 = 2 (3번의 부모는 2번)
// 부모의 번호는 항상 자식의 번호보다 작다. (Pi < Ni)
