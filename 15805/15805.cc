#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<std::vector<int>> tree;
std::vector<int> parents;
std::unordered_map<int, bool> dict;

int main() {
    size_t num_nodes;
    int parent;
    int root;
    int cnt = 1;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> num_nodes;
    tree = std::vector<std::vector<int>>(num_nodes);
    parents = std::vector<int>(num_nodes, INT32_MIN);

    parent = -1;
    root = -1;
    for (size_t i = 0; i < num_nodes; ++i) {
        int n;

        std::cin >> n;
        if (parent != -1 && dict.find(n) == dict.end()) {
            parents[n] = parent;
            tree[parent].push_back(n);
            cnt++;
        }

        if (root == -1) {
            root = n;
            parents[root] = -1;
        }
        dict[n] = true;
        parent = n;
    }
    std::cout << cnt << "\n";
    for (int i : parents) {
        if (i == INT32_MIN) {
            continue;
        }

        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
