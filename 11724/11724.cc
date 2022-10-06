#include <algorithm>
#include <iostream>
#include <vector>

using nodes_t = std::vector<int>;
using graph_t = std::vector<nodes_t>;

void dfs(graph_t &grph, nodes_t &visited, int node);
int main() {
    graph_t graph;
    nodes_t visited;
    int N, M, cnt;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;
    graph = graph_t(N + 1);
    visited = nodes_t(N + 1, 0);

    for (int m = 0; m < M; ++m) {
        int from, to;

        std::cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (int n = 1; n < N + 1; ++n) {
        std::sort(graph[n].begin(), graph[n].end());
    }

    cnt = 0;
    for (int i = 1; i < N + 1; ++i) {
        if (visited[i])
            continue;
        cnt++;
        dfs(graph, visited, i);
    }

    std::cout << cnt << "\n";
    return 0;
}

void dfs(graph_t &grph, nodes_t &visited, int node) {
    nodes_t *nodes = &grph[node];

    for (auto iter = nodes->begin(); iter != nodes->end(); ++iter) {
        if (!visited[*iter]) {
            visited[*iter] = 1;
            dfs(grph, visited, *iter);
        }
    }
}
