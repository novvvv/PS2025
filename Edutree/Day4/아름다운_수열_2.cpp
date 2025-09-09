#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int N, M;
int A[100], B[100];

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) 
        cin >> A[i];

    vector<int> b;
    for (int i = 0; i < M; i++) {
        cin >> B[i]; 
        b.push_back(B[i]);
    }

    sort (b.begin(), b.end());


    int ans = 0;
    for (int i = 0; i <= N - M; i++) {

        vector<int> copy_vec_a;
        for (int j = 0; j < M; j++) {
            copy_vec_a.push_back(A[i+j]);
        }

        sort(copy_vec_a.begin(), copy_vec_a.end());

        bool flag = true;
        for (int ptr = 0; ptr < M; ptr++) {
            if(copy_vec_a[ptr] != b[ptr]) {
                flag = false;
                break;
            }
        }

        if (flag) ans++;
        
    }

    cout << ans << endl;

    return 0;
}
