#include <iostream>
#include <queue>
#include <vector>

std::vector<int> in_degrees;
std::vector<std::vector<int>> dag;

void topology_sort(int n, std::vector<int> &sorted);

int main() {
    int N, M;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N >> M;

    in_degrees = std::vector<int>(N + 1, 0);
    dag = std::vector<std::vector<int>>(N + 1);

    for (int i = 0; i < M; ++i) {
        int small, tall;

        std::cin >> small >> tall;
        in_degrees[tall]++;
        dag[small].push_back(tall);
    }

    std::vector<int> ans;
    topology_sort(N, ans);

    for (auto i = ans.begin(); i != ans.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    return 0;
}

void topology_sort(int n, std::vector<int> &sorted) {
    std::queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (in_degrees[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();

        q.pop();
        sorted.push_back(node);

        for (auto n = dag[node].begin(); n != dag[node].end(); ++n) {
            --in_degrees[(*n)];
            if (in_degrees[(*n)] == 0) {
                q.push(*n);
            }
        }
    }
}
