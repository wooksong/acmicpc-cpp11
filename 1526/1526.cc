#include <iostream>

bool check(int num);

int main() {
    int N;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N;

    for (int i = N; i > 0; --i) {
        if (check(i)) {
            std::cout << i << "\n";
            break;
        }
    }

    return 0;
}

bool check(int num) {
    std::string str_num = std::to_string(num);

    for (auto iter = str_num.begin(); iter != str_num.end(); ++iter) {
        if (*iter != '4' && *iter != '7') {
            return false;
        }
    }

    return true;
}
