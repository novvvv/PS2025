#include <iostream>
#include <string>

using namespace std;

string A;

int main() {

    cin >> A;
    int cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '(' && i + 1 != A.size()) {
            if (A[i + 1] == '(') {
                for (int j = i + 2; j < A.size(); j++) {
                    if (A[j] == ')' && j + 1 != A.size()) {
                        if (A[j + 1] == ')') {
                            cnt++;
                        }
                    }
                }
            }
        }
    }

    cout << cnt << '\n';


    return 0;
}
