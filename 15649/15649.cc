#include <iostream>
#include <vector>

std::vector<bool> visited;

void dfs(std::vector<int> &arr, int depth, int n, int r);

int main() {
    std::vector<int> arr;
    int N, M;

    // freopen("input.txt", "r", stdin);

    std::cin >> N >> M;
    visited = std::vector<bool>(N, false);
    arr = std::vector<int>(M);

    dfs(arr, 0, N, M);

    return 0;
}

void dfs(std::vector<int> &arr, int depth, int n, int r) {
    if (depth == r) {
        for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << "\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            arr[depth] = i + 1;
            dfs(arr, depth + 1, n, r);
            visited[i] = false;
        }
    }
}
