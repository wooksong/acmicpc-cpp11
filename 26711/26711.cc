#include <iostream>
#include <vector>

int main() {
    std::vector<int> ans;
    std::string l_str, r_str;
    size_t l_len, r_len, pos;
    bool leading_zero = true;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> l_str >> r_str;

    l_len = l_str.length();
    r_len = r_str.length();

    if (l_len < r_len) {
        std::swap(l_str, r_str);
        std::swap(l_len, r_len);
    }

    ans = std::vector<int>(l_len + 1, 0);

    pos = 0;
    while (pos < l_len) {
        int d =
            ans[pos] + static_cast<int>(l_str[l_len - 1 - pos] - '0') +
            (r_len <= pos ? 0 : static_cast<int>(r_str[r_len - 1 - pos] - '0'));
        int carry = d / 10;

        ans[pos] = d % 10;
        ans[pos + 1] += carry;

        pos++;
    }

    /*
    while (pos < l_len) {
        int d = ans[pos] + static_cast<int>(l_str[l_len - 1 - pos] - '0');
        int carry = d / 10;

        ans[pos] = d % 10;
        ans[pos + 1] += carry;

        pos++;
    }
    */

    for (auto iter = ans.rbegin(); iter != ans.rend(); ++iter) {
        if (leading_zero) {
            if (*iter == 0)
                continue;
            leading_zero = false;
        }

        std::cout << *iter;
    }

    std::cout << "\n";

    return 0;
}
