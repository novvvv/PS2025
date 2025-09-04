#include <iostream>

using namespace std;

int x1[2], y1[2];
int x2[2], y2[2];

const int MAX_SIZE = 4001;
const int offset = 1000;
int board[MAX_SIZE][MAX_SIZE] = {0, };

int main() {
    
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];

    for (int x = x1[0] + offset; x < x2[0] + offset; x++) {
        for (int y = y1[0] + offset; y < y2[0] + offset; y++) {
            board[x][y] = 1;
        }
    }

    for (int x = x1[1] + offset; x < x2[1] + offset; x++) {
        for (int y = y1[1] + offset; y < y2[1] + offset; y++) {
            board[x][y] = 0;
        }
    }

    int min_x = 2001, min_y = 2001, max_x = -1, max_y = -1;
    bool is_true = false;
    for (int x = 0; x < MAX_SIZE; x++) {
        for (int y = 0; y < MAX_SIZE; y++) {
            if (board[x][y] == 1) {
                is_true = true;
                if (x < min_x) min_x = x;
                if (x > max_x) max_x = x;
                if (y < min_y) min_y = y;
                if (y > max_y) max_y = y;
            }
        }
    }

    if (is_true) {
        int area = (max_x - min_x + 1) * (max_y - min_y + 1);
        cout << area << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}
