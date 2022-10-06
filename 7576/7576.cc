#include <deque>
#include <iostream>
#include <vector>

constexpr int MAX_LEN = 1001;
enum Status {
    NONE = -1,
    IMMATURED = 0,
    MATURED = 1,
};

const std::vector<std::pair<int, int>> d_move = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0},
};
struct Tomato {
    int time;
    Status tomato_status;
};

Tomato box[MAX_LEN][MAX_LEN];
std::deque<std::pair<int, int>> queue;

void bfs(int num_rows, int num_cols);

int ans = INT32_MIN;
int num_immatured = 0;

int main() {
    int M, N;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    std::cin >> M >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int s;
            Tomato t;

            std::cin >> s;
            t.tomato_status = static_cast<Status>(s);
            t.time = INT32_MAX;

            if (t.tomato_status == Status::IMMATURED) {
                num_immatured++;
            }
            box[i][j] = t;
        }
    }

    if (num_immatured == 0) {
        ans = 0;
        goto ret_prnans;
    }

    bfs(N, M);

    if (num_immatured > 0) {
        ans = -1;
    }

ret_prnans:
    std::cout << ans << "\n";

    return 0;
}

void bfs(int num_rows, int num_cols) {
    std::pair<int, int> loc;

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            if (box[i][j].tomato_status == Status::MATURED) {
                queue.push_back({i, j});
                box[i][j].time = 0;
            }
        }
    }

    while (!queue.empty()) {
        loc = queue.front();
        queue.pop_front();

        if (box[loc.first][loc.second].tomato_status == Status::IMMATURED) {
            --num_immatured;
            box[loc.first][loc.second].tomato_status = Status::MATURED;
        }

        for (auto d : d_move) {
            int loc_r, loc_c;

            loc_r = d.first + loc.first;
            loc_c = d.second + loc.second;

            if (loc_r < 0 || loc_r >= num_rows || loc_c < 0 ||
                loc_c >= num_cols)
                continue;

            if (box[loc_r][loc_c].tomato_status == Status::IMMATURED &&
                (box[loc_r][loc_c].time == INT32_MAX)) {
                queue.push_back({loc_r, loc_c});
                box[loc_r][loc_c].time = box[loc.first][loc.second].time + 1;
                ans = std::max(ans, box[loc_r][loc_c].time);
            }
        }
    }
}
