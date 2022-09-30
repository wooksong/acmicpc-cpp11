#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> nodes;
std::vector<bool> visited;

void bfs(int v);
void dfs(int v);

int main() {
    int n_nodes, n_edges;
    int init_node;

    // freopen("input.txt", "r", stdin);

    std::cout.tie(nullptr);

    std::cin >> n_nodes >> n_edges >> init_node;
    nodes = std::vector<std::vector<int>>(n_nodes + 2);
    for (int i = 0; i < n_edges; ++i) {
        int from, to;

        std::cin >> from >> to;
        nodes[from].push_back(to);
        nodes[to].push_back(from);
    }

    for (int i = 0; i < n_nodes + 2; ++i) {
        std::vector<int> *v = &nodes[i];

        std::sort(v->begin(), v->end());
    }

    // DFS
    {
        visited = std::vector<bool>(n_nodes + 2, false);
        dfs(init_node);
        std::cout << "\n";
    }

    // BFS
    {
        for (int i = 0; i < n_nodes + 2; ++i) {
            visited[i] = false;
        }
        bfs(init_node);
        std::cout << "\n";
    }

    return 0;
}

void dfs(int v) {
    visited[v] = true;
    std::cout << v << " ";

    for (auto iter = nodes[v].begin(); iter != nodes[v].end(); ++iter) {
        if (!visited[*iter]) {
            dfs(*iter);
        }
    }
}

void bfs(int v) {
    std::deque<int> q;

    q.push_back(v);
    visited[v] = true;

    while (!q.empty()) {
        int next = q.front();

        q.pop_front();
        std::cout << next << " ";

        for (auto iter = nodes[next].begin(); iter != nodes[next].end();
             ++iter) {
            if (!visited[*iter]) {
                q.push_back(*iter);
                visited[*iter] = true;
            }
        }
    }
}
