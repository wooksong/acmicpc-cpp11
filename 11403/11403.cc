#include <deque>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> visit_table;

int main() {
    int N;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;

    graph = std::vector<std::vector<int>>(N);
    visit_table = std::vector<std::vector<int>>(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int con;

            std::cin >> con;

            if (con) {
                graph[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        std::vector<int> *g = &graph[i];
        std::deque<int> queue;

        for (auto iter = g->begin(); iter != g->end(); ++iter) {
            queue.push_back(*iter);
        }

        while (!queue.empty()) {
            std::vector<int> *to_g;
            int to = queue.front();

            queue.pop_front();

            visit_table[i][to] = 1;
            to_g = &graph[to];

            for (auto iter = to_g->begin(); iter != to_g->end(); ++iter) {
                if (visit_table[i][*iter] == 0)
                    queue.push_back(*iter);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << visit_table[i][j] << " ";
        }

        std::cout << "\n";
    }
    return 0;
}
