#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

constexpr int MAX_LEN_MAP = 26;
int map[MAX_LEN_MAP][MAX_LEN_MAP];

int bfs(int r, int c, int len);

int main() {
    std::vector<int> houses;
    int N;

    // freopen("input.txt", "r", stdin);

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::string line;

        std::cin >> line;
        for (int j = 0; j < N; ++j) {
            map[i][j] = line[j] - '0';
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (map[i][j] == 1) {
                int cnt = bfs(i, j, N);

                houses.push_back(cnt);
            }
        }
    }

    std::sort(houses.begin(), houses.end());

    std::cout << houses.size() << "\n";
    for (auto iter = houses.begin(); iter != houses.end(); ++iter) {
        std::cout << *iter << "\n";
    }

    return 0;
}

int bfs(int r, int c, int len) {
    int ret = 0;
    std::deque<std::pair<int, int>> queue;
    std::vector<std::pair<int, int>> d_move = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    queue.push_back({r, c});
    while (!queue.empty()) {
        std::pair<int, int> cur = queue.front();

        queue.pop_front();
        if (map[cur.first][cur.second] == 1) {
            map[cur.first][cur.second] = 2;
            ret++;
        }

        for (auto iter = d_move.begin(); iter != d_move.end(); ++iter) {
            int move_r, move_c;

            move_r = cur.first + (*iter).first;
            move_c = cur.second + (*iter).second;

            if (move_r < 0 || move_r >= len || move_c < 0 || move_c >= len) {
                continue;
            }

            if (map[move_r][move_c] == 1 &&
                std::find(queue.begin(), queue.end(),
                          std::make_pair(move_r, move_c)) == queue.end()) {
                queue.push_back({move_r, move_c});
            }
        }
    }

    return ret;
}
