#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string input, target; 
    cin >> input >> target; 
    
    string cmp = "";

    for (int i = 0; i < input.length(); i++) {
        if ('0' <= input[i] && input[i] <= '9') continue;
        else cmp.push_back(input[i]);
    }

    if (cmp.find(target) != string::npos) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

}

