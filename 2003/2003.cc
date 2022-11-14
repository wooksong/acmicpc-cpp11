#include <iostream>
#include <vector>

int main() {
    std::vector<int> seq;
    int N, M, sum, cnt;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;

    seq = std::vector<int>(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> seq[i];
    }

    cnt = 0;
    sum = 0;
    int j = 0;
    for (int i = 0; i < N; ++i) {
        while ((j < N) && (sum < M)) {
            sum += seq[j];
            j++;
        }

        if (sum == M) {
            cnt++;
        }
        sum -= seq[i];
    }

    std::cout << cnt << "\n";

    return 0;
}
