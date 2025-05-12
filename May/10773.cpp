#include <iostream>
#include <queue>
using namespace std;

int main() {
    int k;
    cin >> k;
    deque<int> q;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            q.pop_front();
        }
        else {
            q.push_front(num);
        }
    }
    
    //  [4, 5, 3, 1]
    
    int res = 0;
    while(true) {
        if (q.empty())
            break;
        else{
            res += q.front();
            q.pop_front();
        }
    }
    cout << res << '\n';
   return 0;
}

// 잘못된 수를 부른다. -> 0. 가장 최근에 재민이가 쓴 수를 지운다)

// 1 6
