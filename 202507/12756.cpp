#include <iostream>
using namespace std;

int main() {

    int a_atk, a_hp, b_atk, b_hp;
    cin >> a_atk >> a_hp >> b_atk >> b_hp;

    while (true) {
        
        if (a_hp <= 0 && b_hp <= 0) {
            cout << "DRAW" << '\n';
            break;
        }
        else if (a_hp <= 0) {
            cout << "PLAYER B" << '\n';
            break;
        }
        else if (b_hp <= 0){
            cout << "PLAYER A" << '\n';
            break;
        }
        
        a_hp -= b_atk;
        b_hp -= a_atk;
    }

}

// 왼쪽 : 공격력, 오른쪽 : 생명력
// 비교하는 카드의 공격력만큼 상대 카드의 생명력을 깎는다.
// 생명력이 0 이하인 경우에는 죽은 상태로 전환된다.
// 카드 두 장이 모두 남아있다면 계속 비교한다.
