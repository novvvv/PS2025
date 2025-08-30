#include <iostream>

using namespace std;

int a, b, c;

int main() {

    cin >> a >> b >> c;

    int end_time = c + b * 60 + a * 24 * 60;
    int ans = end_time - ((11) + (60 * 11) + (11 * 24 * 60));

    if (ans < 0) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }
    return 0;
}
