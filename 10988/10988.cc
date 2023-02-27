#include <iostream>

int main() {
    std::string word;
    size_t len;
    bool is_palindrome = true;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> word;

    len = word.length();
    for (size_t i = 0; i < len; ++i) {
        size_t j = len - 1 - i;

        if (i >= j) {
            break;
        }
        if (word[i] != word[len - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    std::cout << is_palindrome << "\n";

    return 0;
}
