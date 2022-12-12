#include <iostream>
#include <vector>

constexpr size_t NUM_ALPHABETS = 26;

struct Node {
    char val;
    char lc;
    char rc;

    Node() {
        val = '.';
        lc = '.';
        rc = '.';
    };
};

std::vector<Node> nodes;

void traverse_preorder(int idx_p);
void traverse_inorder(int idx_p);
void traverse_postorder(int idx_p);

int main() {
    int num_nodes;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> num_nodes;
    nodes = std::vector<Node>(NUM_ALPHABETS);

    for (int i = 0; i < num_nodes; ++i) {
        int idx_p;
        char p, lc, rc;
        Node *node;

        std::cin >> p >> lc >> rc;
        idx_p = static_cast<int>(p - 'A');

        node = &(nodes[idx_p]);
        node->val = p;
        node->lc = lc;
        node->rc = rc;
    }

    traverse_preorder(0);
    std::cout << "\n";

    traverse_inorder(0);
    std::cout << "\n";

    traverse_postorder(0);
    std::cout << "\n";

    return 0;
}

void traverse_preorder(int idx_p) {
    char val_p = nodes[idx_p].val;
    int idx_lc, idx_rc;

    if (val_p == '.') {
        return;
    }

    std::cout << val_p;

    if (nodes[idx_p].lc != '.') {
        idx_lc = static_cast<int>(nodes[idx_p].lc - 'A');
        traverse_preorder(idx_lc);
    }

    if (nodes[idx_p].rc != '.') {
        idx_rc = static_cast<int>(nodes[idx_p].rc - 'A');
        traverse_preorder(idx_rc);
    }
}

void traverse_inorder(int idx_p) {
    char val_p = nodes[idx_p].val;
    int idx_lc, idx_rc;

    if (val_p == '.') {
        return;
    }

    if (nodes[idx_p].lc != '.') {
        idx_lc = static_cast<int>(nodes[idx_p].lc - 'A');
        traverse_inorder(idx_lc);
    }

    std::cout << val_p;

    if (nodes[idx_p].rc != '.') {
        idx_rc = static_cast<int>(nodes[idx_p].rc - 'A');
        traverse_inorder(idx_rc);
    }
}

void traverse_postorder(int idx_p) {
    char val_p = nodes[idx_p].val;
    int idx_lc, idx_rc;

    if (val_p == '.') {
        return;
    }

    if (nodes[idx_p].lc != '.') {
        idx_lc = static_cast<int>(nodes[idx_p].lc - 'A');
        traverse_postorder(idx_lc);
    }

    if (nodes[idx_p].rc != '.') {
        idx_rc = static_cast<int>(nodes[idx_p].rc - 'A');
        traverse_postorder(idx_rc);
    }

    std::cout << val_p;
}
