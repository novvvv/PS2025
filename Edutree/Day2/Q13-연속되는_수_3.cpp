#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
int arr[1000];

vector<int> max_length;

int main() {
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    string converter = "plus";
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        
        // 부호가 마이너스인 케이스
        if (arr[i] < 0) {
            if (converter == "plus") {
                max_length.push_back(cnt);
                cnt = 0;
            }
            converter = "minus";
            cnt++;
        }
        
        // 부호가 플러스인 케이스
        else {
            if (converter == "minus") {
                max_length.push_back(cnt);
                cnt = 0;
            }
            converter = "plus";
            cnt++;
        }
        
    }
    
     max_length.push_back(cnt);
     cout << *max_element(max_length.begin(), max_length.end()) << '\n';
    
    
    return 0;
}
