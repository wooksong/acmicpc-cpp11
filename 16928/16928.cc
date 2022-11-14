#include <bitset>
#include <deque>
#include <iostream>
#include <vector>

constexpr int LEN_MAP = 101;
std::vector<int> map(LEN_MAP, 0);
std::bitset<LEN_MAP> visited;
int ans = INT32_MAX;
void bfs();

int main() {
    int num_ladders, num_snakes;
    int num_events;

    // std::freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> num_ladders >> num_snakes;
    num_events = num_ladders + num_snakes;
    for (int i = 0; i < num_events; ++i) {
        int from, to;

        std::cin >> from >> to;

        map[from] = to;
    }

    visited.reset();
    bfs();
    std::cout << ans << "\n";
    return 0;
}

void bfs() {
    const std::vector<int> d_move({1, 2, 3, 4, 5, 6});
    std::deque<std::pair<int, int>> q;
    int start = 1;

    q.push_back({start, 0});
    while (!q.empty()) {
        int cur = q.front().first;
        int steps = q.front().second;

        q.pop_front();

        if (cur == (LEN_MAP - 1)) {
            ans = std::min(ans, steps);
        }

        for (int m : d_move) {
            int next = cur + m;

            if (next < LEN_MAP && (!visited.test(next))) {

                visited.set(next);

                if (!map[next]) {
                    q.push_back({next, steps + 1});
                } else {
                    visited.set(map[next]);
                    q.push_back({map[next], steps + 1});
                }
            }
        }
    }
}
