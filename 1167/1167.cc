#include <iostream>
#include <queue>
#include <vector>

using tree_t = std::vector<std::vector<std::pair<int, int>>>;
tree_t tree;

std::pair<int, int> farthest;
std::vector<int> longest_path;
void find_longest_path(int from);

int main() {
    int num_nodes;

    // freopen("input.txt", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> num_nodes;

    tree = tree_t(num_nodes + 1);
    longest_path = std::vector<int>(num_nodes + 1, -1);

    for (int i = 1; i <= num_nodes; ++i) {
        int node;
        int to;

        std::cin >> node;
        while (std::cin >> to) {
            int w;

            if (to == -1) {
                break;
            }
            std::cin >> w;
            tree[node].push_back({to, w});
        }
    }

    find_longest_path(1);
    std::fill_n(longest_path.begin(), num_nodes + 1, -1);
    find_longest_path(farthest.first);
    std::cout << farthest.second << "\n";

    return 0;
}

struct Compare {
    bool operator()(std::pair<int, int> &lhs, std::pair<int, int> &rhs) {
        if (lhs.second < rhs.second) {
            return true;
        } else if (lhs.second == rhs.second) {
            return lhs.first > rhs.first;
        }

        return false;
    };
};

void find_longest_path(int from) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        Compare>
        pq;

    pq.push({from, 0});
    longest_path[from] = 0;
    farthest = {0, 0};

    while (!pq.empty()) {
        std::pair<int, int> from_node = pq.top();

        pq.pop();

        if (farthest.second < from_node.second) {
            farthest.first = from_node.first;
            farthest.second = from_node.second;
        }

        if (longest_path[from_node.first] > from_node.second)
            continue;

        longest_path[from_node.first] = from_node.second;

        for (std::pair<int, int> to_node : tree[from_node.first]) {
            if (longest_path[to_node.first] != -1)
                continue;

            if (longest_path[to_node.first] <
                longest_path[from_node.first] + to_node.second) {
                longest_path[to_node.first] =
                    longest_path[from_node.first] + to_node.second;
                pq.push({to_node.first,
                         longest_path[from_node.first] + to_node.second});
            }
        }
    }
}
