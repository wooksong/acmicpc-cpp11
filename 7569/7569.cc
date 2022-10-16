#include <deque>
#include <iostream>
#include <vector>

constexpr int MAX_SIZE = 101;

int warehouse[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int days[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int num_cols;
int num_rows;
int height;

struct Coord {
    int x;
    int y;
    int z;
};

void bfs(std::deque<Coord> &queue, int &num_unaged);

int main() {
    std::deque<Coord> queue;
    int num_unaged_tomatos = 0;
    int num_aged_tomatos = 0;
    int ans = -1;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> num_cols >> num_rows >> height;

    for (int h = 0; h < height; ++h) {
        for (int r = 0; r < num_rows; ++r) {
            for (int c = 0; c < num_cols; ++c) {
                int tomato;
                std::cin >> tomato;

                if (tomato == 0) {
                    num_unaged_tomatos++;
                    days[h][r][c] = MAX_SIZE;
                } else if (tomato == 1) {
                    num_aged_tomatos++;
                    queue.push_back({c, r, h});
                    days[h][r][c] = 0;
                }
                warehouse[h][r][c] = tomato;
            }
        }
    }

    if (num_aged_tomatos != (height * num_rows * num_cols)) {
        bfs(queue, num_unaged_tomatos);

        if (num_unaged_tomatos != 0) {
            ans = -1;
        } else {
            ans = INT32_MIN;
            for (int h = 0; h < height; ++h) {
                for (int r = 0; r < num_rows; ++r) {
                    for (int c = 0; c < num_cols; ++c) {
                        ans = std::max(ans, days[h][r][c]);
                    }
                }
            }
        }
    } else {
        ans = 0;
    }

    std::cout << ans << "\n";
    return 0;
}

void bfs(std::deque<Coord> &queue, int &num_unaged) {
    std::vector<Coord> d_move = {{-1, 0, 0}, {1, 0, 0},  {0, -1, 0},
                                 {0, 1, 0},  {0, 0, -1}, {0, 0, 1}};

    while (!queue.empty()) {
        Coord cur = queue.front();

        if (warehouse[cur.z][cur.y][cur.x] == 0) {
            num_unaged--;
            warehouse[cur.z][cur.y][cur.x] = 1;
        }

        queue.pop_front();
        for (auto iter = d_move.begin(); iter != d_move.end(); ++iter) {
            Coord next;

            next.x = cur.x + (*iter).x;
            if (next.x >= num_cols || next.x < 0)
                continue;

            next.y = cur.y + (*iter).y;
            if (next.y >= num_rows || next.y < 0)
                continue;

            next.z = cur.z + (*iter).z;
            if (next.z >= height || next.z < 0)
                continue;

            if ((warehouse[next.z][next.y][next.x] == 0) &&
                (days[next.z][next.y][next.x] == MAX_SIZE)) {
                days[next.z][next.y][next.x] = days[cur.z][cur.y][cur.x] + 1;
                queue.push_back(next);
            }
        }
    }
}
