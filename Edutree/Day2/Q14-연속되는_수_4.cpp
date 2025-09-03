#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arr[1000];
vector<int> ans; 

int main() {

    cin >> N;

    int cnt = 1;
    for (int i = 0; i < N; i++) {
        if (i == 0) continue; 
        cin >> arr[i];
        if (arr[i-1] < arr[i]) {
            cnt++;
        }
        else {
            ans.push_back(cnt);
            cnt = 1;
        }
    }

    ans.push_back(cnt);
    cout << *max_element(ans.begin(), ans.end()) << '\n';


    return 0;
}
