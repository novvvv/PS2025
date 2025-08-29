#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, B;
vector<int> base4_vec; 

int main() {
    
    cin >> N >> B;
    while (N > 0) {
        base4_vec.push_back(N % B);
        N /= B;
    }

    reverse(base4_vec.begin(), base4_vec.end());
    for (int i = 0; i < base4_vec.size(); i++) {
        cout << base4_vec[i];
    }

    return 0;
}
