#include <iostream>
#include <vector>

void dfs(std::vector<int> &arr, int depth, int n, int r);

int main() {
    std::vector<int> arr;
    int N, M;

    //  freopen("input.txt", "r", stdin);

    std::cin >> N >> M;
    arr = std::vector<int>(M);

    dfs(arr, 0, N, M);

    return 0;
}

void dfs(std::vector<int> &arr, int depth, int n, int r) {
    if (depth == r) {
        for (int i = 0; i < r; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        arr[depth] = i + 1;
        dfs(arr, depth + 1, n, r);
    }
}
