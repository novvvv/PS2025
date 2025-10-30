#include <iostream>
#include <string>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, d;
    cin >> n >> d;
    char digit = d + '0';
    
    int num = 0;
    for (int i = 1; i <= n; i++) {
        string str = to_string(i);
//        cout << "[d] i : " << str << " " << digit << endl;
        for (int ptr = 0; ptr < str.length(); ptr++) {
            if (str[ptr] == digit) num++;
        }
    }
    
    cout << num << '\n';
     
}
