#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

string N;

vector<char> base2_to_base10;
vector<int> base10_to_base2;

int main() {

    cin >> N;
    for (int i = 0; i < N.length(); i++) {
        base2_to_base10.push_back(N[i]);
    }

    // 2진수를 10진수로 변환 
    int ans = 0;
    reverse(base2_to_base10.begin(), base2_to_base10.end());
    for (int i = 0; i < base2_to_base10.size(); i++) {
        ans += (base2_to_base10[i] - '0') * pow(2, i);
    }

    ans *= 17;

    while(ans > 0) {
        base10_to_base2.push_back(ans % 2);
        ans /= 2;
    }
    reverse(base10_to_base2.begin(), base10_to_base2.end());
    for (int i = 0; i < base10_to_base2.size(); i++) {
        cout << base10_to_base2[i];
    }

    
    return 0;
}
