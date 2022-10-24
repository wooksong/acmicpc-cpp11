#include <iostream>
#include <vector>

struct Element {
    int val;
    bool is_visited;

    Element() {
        val = -1;
        is_visited = false;
    }

    bool operator<(Element &rhs) { return (val < rhs.val); }
};

std::vector<Element> elements;
std::vector<Element> tmp;
std::vector<int> ans;

void merge(int idx_s, int idx_m, int idx_e);
void sort(int idx_s, int idx_e);
void dfs(int n, int r, int cur, int depth);

int main() {
    int N, M;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> M;
    elements = std::vector<Element>(N);
    tmp = std::vector<Element>(N);
    ans = std::vector<int>(M);

    for (int i = 0; i < N; ++i) {
        std::cin >> elements[i].val;
        elements[i].is_visited = false;
    }

    sort(0, N);
    dfs(N, M, 0, 0);

    return 0;
}

void dfs(int n, int r, int cur, int depth) {
    if (r == depth) {
        for (int i = 0; i < r; ++i) {
            std::cout << ans[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for (int i = cur; i < n; ++i) {
        if (!elements[i].is_visited) {
            elements[i].is_visited = true;
            ans[depth] = elements[i].val;
            dfs(n, r, i, depth + 1);
            elements[i].is_visited = false;
        }
    }
}

void merge(int idx_s, int idx_m, int idx_e) {
    int i, j, pos;

    i = idx_s;
    j = idx_m;
    pos = idx_s;

    while (i < idx_m && j < idx_e) {
        if (elements[i] < elements[j]) {
            tmp[pos++] = elements[i++];
        } else {
            tmp[pos++] = elements[j++];
        }
    }

    while (i < idx_m) {
        tmp[pos++] = elements[i++];
    }

    while (j < idx_e) {
        tmp[pos++] = elements[j++];
    }

    for (i = idx_s; i < idx_e; ++i) {
        elements[i] = tmp[i];
    }
}

void sort(int idx_s, int idx_e) {
    int idx_m;

    if (!(idx_s + 1 < idx_e))
        return;

    idx_m = idx_s + (idx_e - idx_s) / 2;
    sort(idx_s, idx_m);
    sort(idx_m, idx_e);
    merge(idx_s, idx_m, idx_e);
}
