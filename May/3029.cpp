#include <iostream>
#include <string>
using namespace std; 

string current_time_arr[3];
string end_time_arr[3];
void split(string time, char token, string arr[]);

int main () {

    string current_time; 
    string end_time; 

    cin >> current_time >> end_time;
    split(current_time, ':', current_time_arr);
    split(end_time, ':', end_time_arr);

    int current_time_sum = stoi(current_time_arr[0]) * 3600 + stoi(current_time_arr[1]) * 60 + stoi(current_time_arr[2]);
    int end_time_sum = stoi(end_time_arr[0]) * 3600 + stoi(end_time_arr[1]) * 60 + stoi(end_time_arr[2]);
    

    if (current_time_sum >= end_time_sum) {
        end_time_sum += 24 * 60 * 60; 
    }

    int ans = end_time_sum - current_time_sum; 

    int hour = ans / 3600; 
    ans %= 3600;
    int min = ans / 60;
    int sec = ans % 60;

    printf("%02d:%02d:%02d\n", hour, min, sec);
    
}

void split(string time, char token, string arr[]) {
    int split_idx = 0;
    
    for (int i = 0; i < time.size(); i++) {
        if (time[i] == token) {
            split_idx++;
            continue;
        }
        arr[split_idx] += time[i];
    }
}
