#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<uint64_t, bool> cd_collection;
    uint64_t N, M, cnt;

    // freopen("input.txt", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (true) {
        std::cin >> N >> M;

        if (N == 0 && M == 0) {
            break;
        }
        cd_collection.clear();
        cd_collection.reserve(N);

        for (uint64_t i = 0; i < N; ++i) {
            uint64_t num_cd;

            std::cin >> num_cd;
            cd_collection[num_cd] = true;
        }

        cnt = 0;
        for (uint64_t i = 0; i < M; ++i) {
            uint64_t num_cd;

            std::cin >> num_cd;
            if (cd_collection.find(num_cd) == cd_collection.end()) {
                continue;
            }

            cnt++;
        }
        std::cout << cnt << "\n";
    }

    return 0;
}
