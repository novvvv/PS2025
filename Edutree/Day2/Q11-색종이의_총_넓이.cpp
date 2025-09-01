#include <iostream>

using namespace std;

int N;
int x[100], y[100];

const int offset = 100; 
int board[201][201];

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        for (int j = x[i] + offset; j < x[i] + offset + 8; j++) {
            for (int k = y[i] + offset; k < y[i] + 8 + offset; k++) {
                board[j][k] = 1;
            }
        }
    }

    int area = 0;
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++) {
            if (board[i][j] == 1) area++;
        } 
    }

    cout << area << '\n';

    return 0;
}
