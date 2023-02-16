#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::vector<int> seq;
    std::istringstream iss;
    int N, K;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> K;
    std::cin.ignore();

    seq.reserve(N);
    {
        std::string num_strs;
        std::string token;
        size_t num_nums;

        std::getline(std::cin, num_strs);
        iss = std::istringstream(num_strs);

        while (std::getline(iss, token, ',')) {
            bool negative = false;
            int num = 0;
            int mul = 1;

            for (auto iter = token.rbegin(); iter != token.rend(); ++iter) {
                if (*iter == '-') {
                    negative = true;
                    break;
                }
                num += (static_cast<int>(*iter - '0') * mul);
                mul *= 10;
            }

            if (negative) {
                num *= -1;
            }

            seq.push_back(num);
        }

        while (K--) {
            num_nums = seq.size() - 1;
            for (size_t pos = 0; pos < num_nums; ++pos) {
                seq[pos] = seq[pos + 1] - seq[pos];
            }
            seq.pop_back();
        }

        num_nums = seq.size() - 1;
        for (size_t i = 0; i < num_nums; ++i) {
            std::cout << seq[i] << ",";
        }

        std::cout << seq[num_nums] << "\n";
    }

    return 0;
}
