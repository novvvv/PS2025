#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    // M개의 숫자 중 어떤 것을 고를지 표시할 배열(marker)
    std::vector<int> marker(M);

    for (int i = 0; i < N; ++i) {
        marker[i] = 1;
    }

    do {
        for (int i = 0; i < M; ++i) {
            if (marker[i] == 1) {
                std::cout << i + 1 << " ";
            }
        }
        std::cout << "\n";
    } while (std::prev_permutation(marker.begin(), marker.end()));

    return 0;
}

// https://twpower.github.io/82-next_permutation-and-prev_permutation
// https://velog.io/@junhok82/Java%EB%A1%9C-%EC%88%9C%EC%97%B4Permutation-%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0
