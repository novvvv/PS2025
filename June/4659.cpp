#include <iostream>
#include <string>

using namespace std;

int main(){
    
    // 발음이 가능한 패스워드를 만드는것 
    // 1. 모음 (a,e,i,o,u) 하나를 반드시 포함
    // 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안딘다. 
    // 3. 같은 글자가 연속 2번 오면 안되지만 ee, oo는 허용한다.

    string password; 
    while(true) {
        cin >> password; 
        if (password == "end") break; 
        bool condition1 = false, condition2 = false, condition3 = false; 

        // condition1 check 
        // 1. 모음 (a,e,i,o,u) 하나를 반드시 포함
        for (int i = 0; i < password.length(); i++) {
            if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' ||
            password[i] == 'o' || password[i] == 'u') {
                condition1 = true; 
                break;
            }
        }

        // condition2 check 
        // 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안딘다. 
        int vowel_cnt = 0;
        int consonant_cnt = 0;
        for (int i = 0; i < password.length(); i++) {

            if (consonant_cnt >= 3 || vowel_cnt >= 3) break;

            // 모음인 경우
            if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' ||
            password[i] == 'o' || password[i] == 'u') {
                if (consonant_cnt != 0) {
                    consonant_cnt = 0;
                    vowel_cnt++;
                }
                else {
                    vowel_cnt++;
                }
            }
            // 자음인 경우 
            else {
                if (vowel_cnt != 0) {
                    vowel_cnt = 0;
                    consonant_cnt++;
                }
                else {
                    consonant_cnt++;
                }
            }
        }
        if ((vowel_cnt < 3) && (consonant_cnt < 3)){
            condition2 = true; 
        }


        // condition3 check 
        // 3. 같은 글자가 연속 2번 오면 안되지만 ee, oo는 허용한다.

        if (password.length() > 2) {
            for (int i = 0; i < password.length(); i++) {
                if ((password[i] == password[i+1]) && (password[i] != 'e') && (password[i] != 'o')) {
                    condition3 = true; 
                }
            }
        }

        if (condition1 && condition2 && !condition3) {
            cout << "<" << password << "> is acceptable." << '\n'; 
        }
        else {
            cout << "<" << password << "> is not acceptable." << '\n'; 
        }
    }

}

