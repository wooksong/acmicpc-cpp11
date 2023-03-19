#include <deque>
#include <iostream>

constexpr size_t MAX_SIZE = 2000001;

int main() {
    std::deque<int> queue;
    int N, res;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N;
    std::cin.ignore();

    for (int i = 0; i < N; ++i) {
        std::string cmd;

        std::getline(std::cin, cmd);

        switch (cmd[0]) {
        case 'p':
            if (cmd[1] == 'u') {
                std::string num_str = cmd.substr(5UL);
                int m = 1;
                int v = 0;

                for (auto iter = num_str.rbegin(); iter != num_str.rend();
                     ++iter) {
                    v += (static_cast<int>(*iter - '0') * m);
                    m *= 10;
                }
                queue.push_back(v);
            } else {
                res = -1;

                if (!queue.empty()) {
                    res = queue.front();
                    queue.pop_front();
                }

                std::cout << res << "\n";
            }
            break;
        case 's':
            std::cout << queue.size() << "\n";
            break;
        case 'e':
            std::cout << queue.empty() << "\n";

            break;
        case 'f':
            std::cout << (queue.empty() ? -1 : queue.front()) << "\n";
            break;
        case 'b':
            std::cout << (queue.empty() ? -1 : queue.back()) << "\n";
            break;
        default:
            break;
        }
    }

    return 0;
}
