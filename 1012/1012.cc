#include <deque>
#include <iostream>
#include <string.h>
#include <vector>

constexpr int MAX_NUM_ROWS = 51;
constexpr int MAX_NUM_COLS = 51;

enum State {
    NONE = 0,
    CABBAGE = 1,
    VISIT = 2,
};

int bfs(int (&land)[MAX_NUM_ROWS][MAX_NUM_COLS], int num_rows, int num_cols,
        int r, int c);

int main() {
    int land[MAX_NUM_ROWS][MAX_NUM_COLS];
    int num_rows, num_cols, num_cabbages;
    int T;

    // freopen("input.txt", "r", stdin);
    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        int visited;
        int need;

        std::cin >> num_cols >> num_rows >> num_cabbages;

        memset(land, 0, sizeof(land));
        for (int i = 0; i < num_cabbages; ++i) {
            int r, c;

            std::cin >> c >> r;
            land[r][c] = CABBAGE;
        }

        visited = 0;
        need = 0;
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (land[i][j] == CABBAGE) {
                    int v = bfs(land, num_rows, num_cols, i, j);

                    need++;
                    visited += v;
                }
            }
        }

        std::cout << need << "\n";
    }

    return 0;
}

int bfs(int (&land)[MAX_NUM_ROWS][MAX_NUM_COLS], int num_rows, int num_cols,
        int r, int c) {
    std::vector<std::pair<int, int>> d_moves = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::deque<std::pair<int, int>> q;
    int num_visited;

    if (land[r][c] == CABBAGE) {
        q.push_back({r, c});
    }

    num_visited = 0;
    while (!q.empty()) {
        std::pair<int, int> loc;

        loc = q.front();
        q.pop_front();
        if (land[loc.first][loc.second] != CABBAGE)
            continue;
        land[loc.first][loc.second] = VISIT;
        num_visited++;
        for (std::pair<int, int> d_move : d_moves) {
            int moved_r, moved_c;

            moved_r = loc.first + d_move.first;
            moved_c = loc.second + d_move.second;

            if (moved_r >= 0 && moved_r < num_rows && moved_c >= 0 &&
                moved_c < num_cols) {
                if (land[moved_r][moved_c] == CABBAGE) {
                    q.push_back({moved_r, moved_c});
                }
            }
        }
    }

    return num_visited;
}
