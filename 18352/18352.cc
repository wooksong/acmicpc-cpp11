#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::queue<int> q;
    std::vector<std::vector<int>> cities;
    std::vector<int> dis_table;

    int num_v, num_e, t_dis, init_v;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> num_v >> num_e >> t_dis >> init_v;

    cities = std::vector<std::vector<int>>(num_v + 1);
    dis_table = std::vector<int>(num_v + 1, INT32_MAX);

    for (int i = 1; i <= num_e; ++i) {
        int from, to;

        std::cin >> from >> to;

        cities[from].push_back(to);
    }
    dis_table[init_v] = 0;
    q.push(init_v);
    while (!q.empty()) {
        std::vector<int> *next;
        int now;

        now = q.front();
        q.pop();

        next = &cities[now];
        for (auto iter = next->begin(); iter != next->end(); ++iter) {
            if (dis_table[*iter] != INT32_MAX)
                continue;

            dis_table[*iter] = dis_table[now] + 1;
            q.push(*iter);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= num_v; ++i) {
        if (dis_table[i] == t_dis) {
            std::cout << i << "\n";
            cnt++;
        }
    }
    if (cnt == 0) {
        std::cout << "-1\n";
    }
    return 0;
}
