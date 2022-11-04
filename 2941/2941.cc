#include <iostream>

int main() {
    std::string input;
    std::string word;
    size_t len_input;
    size_t cnt = 0;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> input;
    len_input = input.length();

    word = "";
    for (size_t i = 0; i < len_input; ++i) {
        if (input[i] == 'z' && (i + 1) < len_input) {
            if ((i >= 1) && input[i - 1] == 'd' && input[i + 1] == '=') {
                ++i;
                cnt += 2;
            } else if (input[i + 1] == '=') {
                ++i;
                ++cnt;
            }
        } else if (input[i] == 'c' || input[i] == 'd' || input[i] == 's') {
            if ((i + 1) < len_input &&
                (input[i + 1] == '-' || input[i + 1] == '=')) {
                ++i;
                ++cnt;
            }
        } else if (input[i] == 'j') {
            if ((i >= 1) && ((input[i - 1] == 'l') || (input[i - 1] == 'n'))) {
                cnt++;
            }
        }
    }

    std::cout << len_input - cnt << "\n";
    return 0;
}
