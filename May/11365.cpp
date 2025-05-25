#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

int main () {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (true) {
        string input_data; 
        getline(cin, input_data);
        if (input_data == "END") {
            break;
        }
        else {
            reverse(input_data.begin(), input_data.end());
            cout << input_data << '\n';
        }
    }
    

}
