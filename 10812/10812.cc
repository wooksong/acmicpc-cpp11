#include <iostream>
#include <vector>

std::vector<int> buckets;
std::vector<int> tmp_buckets;

int main() {
    int N, M;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> M;
    buckets = std::vector<int>(N, 0);
    tmp_buckets = std::vector<int>(N, 0);

    for (int i = 0; i < N; ++i) {
        buckets[i] = i + 1;
    }

    for (int i = 0; i < M; ++i) {
        int j, k, from, to, pivot;

        std::cin >> from >> to >> pivot;

        k = from - 1;
        j = pivot - 1;

        while (j < to) {
            tmp_buckets[k++] = buckets[j++];
        }

        j = from - 1;
        while (k < to) {
            tmp_buckets[k++] = buckets[j++];
        }

        for (j = from - 1; j < to; ++j) {
            buckets[j] = tmp_buckets[j];
        }
    }

    for (int i : buckets) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
