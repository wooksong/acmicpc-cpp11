#include <bitset>
#include <iostream>
#include <list>
#include <vector>

constexpr int MAX_NUM_NODES = 51;

std::vector<std::list<int>> tree;
std::bitset<MAX_NUM_NODES> visited;

void do_traversal(int root, int removed, int &num_leaves);

int main() {
    int num_nodes, num_leaf_nodes;
    int node_root, node_removed;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> num_nodes;

    tree = std::vector<std::list<int>>(num_nodes);
    for (int i = 0; i < num_nodes; ++i) {
        int p_node;

        std::cin >> p_node;
        if (p_node == -1) {
            node_root = i;
            continue;
        }
        tree[p_node].push_back(i);
    }
    visited.reset();

    std::cin >> node_removed;
    tree[node_removed].clear();

    num_leaf_nodes = 0;
    if (node_removed != node_root) {
        do_traversal(node_root, node_removed, num_leaf_nodes);
    }
    std::cout << num_leaf_nodes << "\n";
    return 0;
}

void do_traversal(int root, int removed, int &num_leaves) {
    std::vector<int> stack;

    stack.push_back(root);

    while (!stack.empty()) {
        int v_node = stack.back();

        visited.set(v_node);
        stack.pop_back();

        for (auto iter = tree[v_node].begin(); iter != tree[v_node].end();
             ++iter) {
            if (*iter == removed) {
                tree[v_node].erase(iter);
                break;
            }
        }

        if (tree[v_node].empty()) {
            num_leaves++;
            continue;
        }

        for (auto iter = tree[v_node].begin(); iter != tree[v_node].end();
             ++iter) {
            if (visited.test(*iter)) {
                continue;
            }
            stack.push_back(*iter);
        }
    }
}
