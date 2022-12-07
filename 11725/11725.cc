#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<int> nodes;

int main() {
    std::queue<std::pair<int, int>> q;
    int num_nodes;

    // freopen("input.txt", "r", stdin);
    std::cin >> num_nodes;
    graph = std::vector<std::vector<int>>(num_nodes + 1);
    nodes = std::vector<int>(num_nodes + 1, -1);
    for (int i = 1; i < num_nodes; ++i) {
        int l, r;

        std::cin >> l >> r;

        graph[l].push_back(r);
        graph[r].push_back(l);
    }

    for (auto iter = graph[1].begin(); iter != graph[1].end(); ++iter) {
        q.push({*iter, 1});
    }

    while (!q.empty()) {
        int child = q.front().first;
        int parent = q.front().second;

        q.pop();

        if (nodes[child] != -1)
            continue;
        nodes[child] = parent;

        for (auto iter = graph[child].begin(); iter != graph[child].end();
             ++iter) {
            q.push({*iter, child});
        }
    }

    for (int i = 2; i <= num_nodes; ++i) {
        std::cout << nodes[i] << "\n";
    }
}
