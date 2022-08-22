#include <iostream>

bool check_even(std::string str_num);

int main() {
    uint32_t N;

    // freopen("input.txt", "r", stdin);
    std::cin >> N;
    for (uint32_t i = 0; i < N; ++i) {
        std::string s_num;

        std::cin >> s_num;
        if (check_even(s_num)) {
            std::cout << "even\n";
            continue;
        }
        std::cout << "odd\n";
    }

    return 0;
}

bool check_even(std::string str_num) {
    uint32_t res = 0;
    for (auto iter = str_num.begin(); iter != str_num.end(); ++iter) {
        res = (res * 10 + static_cast<uint32_t>(*iter - '0')) % 2;
    }

    if (!res)
        return true;
    return false;
}
