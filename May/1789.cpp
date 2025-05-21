#include <iostream>

using namespace std;

int main() {

    cin.tie(0);
    long long s;
    cin >> s; 
    long long left = 1;
    long long right = s; 
    long long mid = (left + right) / 2;
    int ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if ((mid)*(mid+1)/2 <= s) {
            ans = mid;
            left = mid + 1; 
        } 
        else {
            right = mid - 1;

        }
    }

    cout << ans << endl;

}
