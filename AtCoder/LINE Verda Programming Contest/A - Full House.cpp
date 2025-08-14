#include <iostream>
using namespace std;


int main () {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int idx;
    int num_arr[14] = {0, };
    for (int i = 0; i < 5; i++) {
        cin >> idx;
        num_arr[idx]++;
    }
    
    bool is_three = false, is_two = false;
    for (int i = 0; i < 14; i++) {
        if (num_arr[i] == 3) is_three = true;
        if (num_arr[i] == 2) is_two = true;
    }
    
    if (is_three && is_two) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }
    
}

