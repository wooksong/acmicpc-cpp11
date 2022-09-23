#include <iostream>
#include <vector>

int main() {
    std::vector<int> digit_cnts;
    int T;

    // freopen("input.txt", "r", stdin);
    {
        using namespace std;

        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        cin >> T;
    }

    for (int t = 0; t < T; ++t) {
        std::string in;
        size_t len;
        uint64_t lhs = 0;
        uint64_t rhs = 0;
        std::cin >> in;

        len = in.length();
        digit_cnts = std::vector<int>(10, 0);

        for (auto iter = in.begin(); iter != in.end(); ++iter) {
            if (*iter == '6') {
                digit_cnts[9]++;
            } else {
                digit_cnts[(*iter - '0')]++;
            }
        }

        if (len - digit_cnts[0] == 1) {
            std::cout << "0\n";
            continue;
        }
        for (size_t i = 10; i > 0; --i) {
            size_t idx = i - 1;

            if (digit_cnts[idx] == 0)
                continue;

            while (digit_cnts[idx] > 0) {
                int64_t lhs_first;
                int64_t rhs_first;

                lhs_first = lhs * 10 + idx;
                rhs_first = rhs * 10 + idx;
                if ((lhs_first * rhs) >= (lhs * rhs_first)) {
                    lhs = lhs_first;
                } else {
                    rhs = rhs_first;
                }
                (digit_cnts[idx])--;
            }
        }

        std::cout << lhs * rhs << "\n";
    }

    return 0;
}
