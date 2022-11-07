#include <iostream>
#include <queue>
#include <vector>

struct Fish {
    int m_x;
    int m_y;
    int m_dist;

    Fish() {
        m_x = -1;
        m_y = -1;
        m_dist = INT32_MAX;
    }

    Fish(int x, int y, int v) {
        m_x = x;
        m_y = y;
        m_dist = v;
    }

    bool operator<(const Fish rhs) const {
        if (m_dist == rhs.m_dist) {
            if (m_x == rhs.m_x) {
                if (m_y > rhs.m_y) {
                    return true;
                }
                return false;
            } else if (m_x > rhs.m_x) {
                return true;
            } else {
                return false;
            }
        }
        return m_dist > rhs.m_dist;
    }
};

int N;
std::vector<std::vector<int>> map;
std::vector<std::vector<int>> dist_map;
std::priority_queue<Fish> pq_fish;

void bfs(Fish &shaq, int &cur_size);

int main() {
    int cur_size;
    int num_feed;
    Fish shaq;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;

    map = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> map[i][j];
            if (map[i][j] == 9) {
                shaq.m_x = i;
                shaq.m_y = j;
                shaq.m_dist = 0;
            }
        }
    }

    num_feed = 0;
    cur_size = 2;
    int sum = 0;
    while (true) {
        dist_map =
            std::vector<std::vector<int>>(N, std::vector<int>(N, INT32_MAX));
        dist_map[shaq.m_x][shaq.m_y] = 0;
        pq_fish = std::priority_queue<Fish>();

        bfs(shaq, cur_size);
        if (pq_fish.empty())
            break;

        num_feed++;
        if (num_feed == cur_size) {
            num_feed = 0;
            cur_size++;
        }
        shaq = pq_fish.top();
        pq_fish.pop();
        sum += shaq.m_dist;

        shaq.m_dist = 0;
        map[shaq.m_x][shaq.m_y] = 0;
    }

    std::cout << sum << "\n";

    return 0;
}

void bfs(Fish &shaq, int &cur_size) {
    std::vector<std::pair<int, int>> d_move = {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    std::queue<Fish> q;

    q.push(shaq);
    map[shaq.m_x][shaq.m_y] = 0;

    while (!q.empty()) {
        Fish cur = q.front();
        int f_size = map[cur.m_x][cur.m_y];

        if (f_size != 0 && cur_size > f_size) {
            pq_fish.push(cur);
        }

        if (dist_map[cur.m_x][cur.m_y] < cur.m_dist) {
            continue;
        }
        dist_map[cur.m_x][cur.m_y] = cur.m_dist;
        q.pop();

        for (auto p : d_move) {
            int f_x = cur.m_x + p.first;
            int f_y = cur.m_y + p.second;

            if (f_x < 0 || f_x >= N || f_y < 0 || f_y >= N)
                continue;
            if (map[f_x][f_y] > cur_size || dist_map[f_x][f_y] != INT32_MAX)
                continue;
            dist_map[f_x][f_y] = cur.m_dist + 1;
            q.push(Fish(f_x, f_y, cur.m_dist + 1));
        }
    }
}
