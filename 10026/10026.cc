#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

struct RGB {
    char color;
    bool is_visited;
};

std::vector<std::vector<RGB>> picture;
void bfs(int n, int r, int c, char color);

int main() {
    std::unordered_map<char, int> area_cnts = {{'R', 0}, {'G', 0}, {'B', 0}};
    int N, sum;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;

    picture = std::vector<std::vector<RGB>>(N, std::vector<RGB>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char color;

            std::cin >> color;
            picture[i][j].color = color;
            picture[i][j].is_visited = false;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (picture[i][j].is_visited)
                continue;
            bfs(N, i, j, picture[i][j].color);
            area_cnts[picture[i][j].color]++;
        }
    }

    sum = 0;
    for (auto iter = area_cnts.begin(); iter != area_cnts.end(); ++iter) {
        sum += iter->second;
        iter->second = 0;
    }
    std::cout << sum << " ";

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (picture[i][j].color == 'G')
                picture[i][j].color = 'R';
            picture[i][j].is_visited = false;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (picture[i][j].is_visited)
                continue;
            bfs(N, i, j, picture[i][j].color);
            area_cnts[picture[i][j].color]++;
        }
    }
    sum = 0;
    for (auto iter = area_cnts.begin(); iter != area_cnts.end(); ++iter) {
        sum += iter->second;
    }
    std::cout << sum << "\n";

    return 0;
}

void bfs(int n, int r, int c, char color) {
    std::vector<std::pair<int, int>> d_move = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };
    std::queue<std::pair<int, int>> q;

    q.push(std::make_pair(r, c));
    picture[r][c].is_visited = true;
    while (!q.empty()) {
        int x, y;

        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (auto iter = d_move.begin(); iter != d_move.end(); ++iter) {
            int d_x = x + iter->first;
            int d_y = y + iter->second;

            if (d_x >= n || d_x < 0)
                continue;
            if (d_y >= n || d_y < 0)
                continue;

            if (!picture[d_x][d_y].is_visited &&
                picture[d_x][d_y].color == color) {
                picture[d_x][d_y].is_visited = true;
                q.push(std::make_pair(d_x, d_y));
            }
        }
    }
}
