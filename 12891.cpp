#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    cin.tie(0);
    // 임의의 DNA문자열을 만든 뒤 만들어진 DNA의 문자열의 부분문자열을 비밀번호로 사용한다.
    // - 단, 부분 문자열에 등장하는 문자의 개수가 특정 개수 이상이어야 비밀번호로 사용 가능하다.
    int s, p; // 문자열 길이, 부분 문자열 길이
    cin >> s >> p;
    
    string str;
    cin >> str;
    
    // {A, C, G, T}
    vector<int> alpha(4);
    for (int i = 0; i < 4; i++)
        cin >> alpha[i];
    
    map<char, int> alpha_map;
    for (int i = 0; i < p; i++) {
        if (str[i] == 'A') alpha_map['A']++;
        else if (str[i] == 'C') alpha_map['C']++;
        else if (str[i] == 'G') alpha_map['G']++;
        else if (str[i] == 'T') alpha_map['T']++;
    }
    
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        if (alpha_map['A'] >= alpha[0] && alpha_map['C'] >= alpha[1] && alpha_map['G'] >= alpha[2] && alpha_map['T'] >= alpha[3]) flag = true;
    }
    if (flag) ans++;
    
    int wd_st = 0, wd_ed = p - 1;
    while (wd_ed < s-1) {
        
        alpha_map[str[wd_st]]--;
        wd_st++;
        
        wd_ed++;
        alpha_map[str[wd_ed]]++;
        flag = false;
        for (int i = 0; i < 4; i++) {
            if (alpha_map['A'] >= alpha[0] && alpha_map['C'] >= alpha[1] && alpha_map['G'] >= alpha[2] && alpha_map['T'] >= alpha[3]) flag = true;
        }
        if (flag) ans++;
        
//        cout << "loof" << endl;
//        cout << "[debug] wd_st : " << wd_st << ", wd_ed : " << wd_ed << endl;
//        cout << "[debug] {A : " << alpha_map['A'] << ", C : " << alpha_map['C'] << ", G : " << alpha_map['G'] << ", T : " << alpha_map['T'] << "}" << endl;
//        cout << "[debug] {A: " << str[0] << ", C : " << str[1] << ", G : " << str[2] << ", T : " << str[3] << "}" << endl << endl;
        

    }
    cout << ans << endl;
    
}

// 최고 득표자, 과반수득표인지 아닌지 판단
