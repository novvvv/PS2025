#include <iostream>

using namespace std; 

// Brute-Force-GCD
int GCD(int a, int b ) {
    int min_val = (a < b) ? a : b; 
    for (int i = min_val; i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
        return i;
    }
    return 1; 
}

// LCM 
int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

int main() {
    
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t; 
    cin >> t;
    int n1, n2; 
    for (int i = 0; i < t; i++) {
        cin >> n1 >> n2; 
        cout << LCM(n1, n2) << '\n';
    } 

}
