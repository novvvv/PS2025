#include <iostream>

using namespace std;

int n;
char dir[100];
int dist[100];
int main() {

    cin >> n;
    int cur_x = 0; 
    int cur_y = 0;
    for (int i = 0; i < n; i++) {

        cin >> dir[i] >> dist[i];
        if (dir[i] == 'N') cur_y += dist[i];
        else if (dir[i] == 'S') cur_y -= dist[i];
        else if (dir[i] == 'E') cur_x += dist[i];
        else if (dir[i] = 'W') cur_x -= dist[i];

    }

    cout << cur_x << " " << cur_y << '\n';

    return 0;
}
