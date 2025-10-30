#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        
        int n;
        cin >> n;
        vector<int> papers(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> papers[j];
        }
        
        auto max_it = max_element(papers.begin(), papers.end());
        int max_votes = *max_it;
        auto winner_idx = distance(papers.begin(), max_it); // 두 이터레이터 사이의 거리를 계산 (= index)
        int votes_sum = accumulate(papers.begin(), papers.end(), 0);
        
        if (count(papers.begin(), papers.end(), max_votes) >= 2) {
            cout << "no winner" << '\n';
            continue;
        }
        
        if ((votes_sum / 2) < max_votes) {
            cout << "majority winner " << winner_idx + 1 << '\n';
        }
        else {
            cout << "minority winner " << winner_idx + 1 << '\n';
        }
   
    }
     
}

// 최고 득표자, 과반수득표인지 아닌지 판단
