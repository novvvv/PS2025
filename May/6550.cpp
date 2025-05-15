#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main() {
    
    cin.tie(0);
    
    string s, t;
    
    
    // s가 t의 부분 문자열인가?
    while (cin >> s >> t) {
        bool flag = false;
        int s_ptr = 0;
        int t_ptr = 0;
        while (true) {
            if (s_ptr == s.size()) {
                flag = true;
                break;
            }
            if (t_ptr == t.size()) {
                if (s_ptr == s.size()) {
                    flag = true;
                    break;
                }
                flag = false;
                break;
            }
            
            if (s[s_ptr] == t[t_ptr]) {
                s_ptr++;
            }
            
            t_ptr++;
        }
//         cout << "s_ptr : " << s_ptr << " t_ptr : " << t_ptr << endl;
        if (flag) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
       
}
