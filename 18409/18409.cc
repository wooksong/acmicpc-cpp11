#include <iostream>

int main() {
    size_t N, ans;
    std::string S;

    freopen("input.txt", "r", stdin);

    std::cin >> N;
    std::cin >> S;
    ans = 0;
    for (char c : S) {
        switch (c) {
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o':
            ++ans;
        default:
            continue;
        }
    }
    std::cout << ans << "\n";

    return 0;
}
