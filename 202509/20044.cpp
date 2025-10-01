#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> ans_vec;

int main () {
    
    int n;
    cin >> n;
    int input_val;
    for (int i = 0; i < n * 2; i++) {
        cin >> input_val;
        v.push_back(input_val);
    }
    sort(v.begin(), v.end());
    
    while(!v.empty()) {
        ans_vec.push_back(v.front() + v.back());
        v.erase(v.begin());
        v.pop_back();
    }
    
    sort(ans_vec.begin(), ans_vec.end());
    cout << ans_vec[0] << endl;
}

// 프로젝트 팀 하나는 두 명의 학생으로 구성된다.
// 학생들의 코딩 역량은 다르다.
// "팀원들의 코딩 역량의 합을 최대한 일정하게 유지한다"

// 학생 수 2n
// 학생(sj)의 코딩 역량은 w(sj)라고 가정
// i번째 팀 Gi의 코딩 역량은 w(gi)

// 가장 역량이 낮은 팀의 합산 점수를 최대한 높게 만들어라.
// 모든 팀의 역량의 합을 최대한 비슷하게 만들어 팀 간의 격차를 줄이는 것이 목표다.
