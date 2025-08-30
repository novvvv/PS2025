#include <iostream>
#include <string> 
using namespace std;

int m1, d1, m2, d2;

string day[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int cal_total_date(int month, int day) {

    int total_days = 0;
    for (int i = 0; i < month; i++) {
        total_days += days[i];
    }
    total_days += day;
    return total_days; 

}

int main() {

    cin >> m1 >> d1 >> m2 >> d2;

    int ans = cal_total_date(m2, d2) - cal_total_date(m1, d1);
    while (ans < 0) {
        ans += 7; 
    }
    cout << day[ans % 7] << '\n';

    return 0;
}
