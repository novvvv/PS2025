#include <iostream>
#include <cstring>
using namespace std; 

int main () {

    while (true) {

        char input_data[501];
        scanf(" %[^\n]", input_data); // 공백 포함 문자열 입력 (C스타일))

        if (strcmp(input_data, "END") == 0) {
            break;
        }

        else {
            char reversed_input_data[501];
            int len = strlen(input_data);

            for (int i = 0; i < len; i++) {
                reversed_input_data[i] = input_data[len - 1 - i];
            }

            reversed_input_data[len] = '\0'; // 문자열을 구분하기 위한 null 문자
            
            printf("%s\n", reversed_input_data);
        }

    }
    

}
