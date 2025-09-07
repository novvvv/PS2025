#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int cal_binary_to_decimal(string str) {
    int decimal = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '1') {
            decimal += pow(2, i);
        }
    }
    return decimal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    cin >> a;

    reverse(a.begin(), a.end());

    int max_value = 0;

    for (int i = 0; i < a.length(); i++) {
        string copy_str = a; 

        if (copy_str[i] == '0') {
            copy_str[i] = '1';
        } else { 
            copy_str[i] = '0';
        }

        int val = cal_binary_to_decimal(copy_str);
        
        if (max_value < val) {
            max_value = val;
        }
    }

    cout << max_value << '\n';

    return 0;
}
