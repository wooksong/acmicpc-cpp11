#include <algorithm>
#include <iostream>
#include <vector>

struct Score {
    int rank_document;
    int rank_interview;
};

int main() {
    struct {
        bool operator()(Score &lhs, Score &rhs) {
            return lhs.rank_document < rhs.rank_document;
        }
    } CompRankDocu;

    std::vector<Score> v;
    int T, N;

    //  freopen("input.txt", "r", stdin);
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int cnt, cut_rank;

        std::cin >> N;
        v.clear();
        for (int n = 0; n < N; ++n) {
            Score in;

            std::cin >> in.rank_document;
            std::cin >> in.rank_interview;

            v.push_back(in);
        }
        std::sort(v.begin(), v.end(), CompRankDocu);
        cnt = 1;
        cut_rank = v[0].rank_interview;
        for (int i = 1; i < N; ++i) {
            if (v[i].rank_interview < cut_rank) {
                cnt++;
                cut_rank = v[i].rank_interview;
            }
        }

        std::cout << cnt << "\n";
    }

    return 0;
}
