#include <iostream>
#include <deque>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        deque<char> q;
        
        for (int i = 0; i < n; i++) {
            char command;
            cin >> command;
            
            // Case1 : 큐가 비어있으면 단순 추가.
            if (q.empty()) {
                q.push_back(command);
            }
            // Case2 : 큐가 비어있지 않다면 사전순 비교
            else {
                char cur_alpha = q.back();
                if (command <= cur_alpha) {
                    q.push_back(command);
                }
                else {
                    q.push_front(command);
                }
            }
        }
        
        while(true) {
            if (q.empty()) break;
            cout << q.back();
            q.pop_back();
        }
        cout << '\n';
        
        
    }
    
    // #1 가장 왼쪽에 있는 카드부터 차례대로 한장 씩 가져온다.
    // #2 가져온 카드는 가장 왼쪽에 두거나 오른쪽에 둘 수 있다.
    // - 결과 : 사전 순으로 가장 빠른 문자열을 출력해야 한다.
    
}


