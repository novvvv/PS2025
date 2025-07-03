#include <iostream>

using namespace std; 

int main () {

    char current_state = 'N';
    int command; 
    for (int i = 0; i < 10; i++) {
        
        cin >> command; 
        
        // 우향우 - 오른쪽으로 90도 회전 
        if (command == 1) {
            if (current_state == 'N') current_state = 'E';
            else if (current_state == 'E') current_state = 'S';
            else if (current_state =='S') current_state = 'W';
            else if (current_state == 'W') current_state = 'N';
        }

        // 뒤로 돌아 - 오른쪽으로 180도 회전
        else if (command == 2) {
            if (current_state == 'N') current_state = 'S';
            else if (current_state == 'E') current_state = 'W';
            else if (current_state == 'S') current_state = 'N';
            else if (current_state == 'W') current_state = 'E';
        }

        // 좌향좌 - 왼쪽으로 90도 회전 
        else if (command == 3) {
            if (current_state == 'N') current_state = 'W';
            else if (current_state == 'E') current_state = 'N';
            else if (current_state == 'S') current_state = 'E';
            else if (current_state == 'W') current_state = 'S';
        }

    }

    cout << current_state << endl; 

}

// 1. 우향우 - 각 학생은 현재 상태에서 오른쪽으로 90도 돈다. 
// 2. 뒤로 돌아 - 각 학생은 현재 상태에서 오른쪽으로 180도 돈다. 
// 3. 좌향좌 - 각 학생은 현재 상태에서 왼쪽으로 90도 돈다. 

// 북쪽 N, 동쪽 E, 서쪽 W, 남쪽 S
