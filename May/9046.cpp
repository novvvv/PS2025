#include <iostream>
#include <cstring>
using namespace std; 

int main () {

    cin.tie(0);
    ios::sync_with_stdio(false); 

    int t;
    cin >> t; 
    cin.ignore();

    string input;
    int arr[26] = {0, };
    for (int i = 0; i < t; i++) {
        
        memset(arr, 0, sizeof(arr));
        getline(cin, input);

        // 아스키 로직을 사용해 알파벳의 빈도를 구함
        for (int j = 0; j < input.size(); j++) {
            if (input[j] == ' ') continue; 
            else {
                arr[input[j]-97]++;
            }
        }

        // 알파벳의 최대 빈도를 구하는 로직 
        int max_alpha_cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (max_alpha_cnt < arr[i]) {
                max_alpha_cnt = arr[i];
            }
        }

        int alpha_idx = -1;
        int is_unique = 0; 
        for (int i = 0; i < 26; i++) {
            if (arr[i] == max_alpha_cnt) {
                alpha_idx = i;
                is_unique++;
            }
        }

        if (is_unique != 1) {
            cout << "?" << '\n';
        }
        else {
            cout << char(97 + alpha_idx) << '\n';
        }

    }


}
