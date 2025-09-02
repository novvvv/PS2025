#include <iostream>

using namespace std;

string dirs;

int cur_x = 0, cur_y = 0;

int main() {

    cin >> dirs;
    char cur_dir = 'N';
    for (int i = 0; i < dirs.length(); i++) {
        
        if (dirs[i] == 'F') {
            if (cur_dir == 'N') cur_y++;
            else if (cur_dir == 'W') cur_x--;
            else if (cur_dir == 'S') cur_y--;
            else if (cur_dir == 'E') cur_x++;
        }
        
        else if (dirs[i] == 'L') {
            if (cur_dir == 'N') cur_dir = 'W';
            else if (cur_dir == 'W') cur_dir = 'S';
            else if (cur_dir == 'S') cur_dir = 'E';
            else if (cur_dir == 'E') cur_dir = 'N';
        }
        
        else if (dirs[i] == 'R') {
            if (cur_dir == 'N') cur_dir = 'E';
            else if (cur_dir == 'W') cur_dir = 'N';
            else if (cur_dir == 'S') cur_dir = 'W';
            else if (cur_dir == 'E') cur_dir = 'S';
        }
        
    }
    
    cout << cur_x << " " << cur_y << '\n';

    return 0;
}
