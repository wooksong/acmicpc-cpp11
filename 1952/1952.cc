#include <iostream>
#include <vector>

int main() {
    std::pair<int, int> direction = {0, 1};
    std::pair<int, int> pos = {0, 0};
    std::pair<int, int> next = {0, 0};
    std::vector<std::vector<int>> map;
    int n_visit, n_change_direction;
    int M, N;

    // freopen("input.txt", "r", stdin);

    std::cin >> M >> N;
    map = std::vector<std::vector<int>>(M, std::vector<int>(N, -1));
    n_visit = M * N;

    n_change_direction = 0;
    map[pos.first][pos.second] = 1;
    while (n_visit > 0) {
        next.first = pos.first + direction.first;
        next.second = pos.second + direction.second;

        if (next.first >= M || next.second >= N ||
            map[next.first][next.second] != -1) {
            if (direction.first == 0 && direction.second == 1) {
                direction.first = 1;
                direction.second = 0;
                n_change_direction++;
            } else if (direction.first == 1 && direction.second == 0) {
                direction.first = 0;
                direction.second = -1;
                n_change_direction++;
            } else if (direction.first == 0 && direction.second == -1) {
                direction.first = -1;
                direction.second = 0;
                n_change_direction++;
            } else if (direction.first == -1 && direction.second == 0) {
                direction.first = 0;
                direction.second = 1;
                n_change_direction++;
            }
        }

        pos.first += direction.first;
        pos.second += direction.second;
        map[pos.first][pos.second] = 1;

        n_visit--;
    }

    std::cout << n_change_direction - 1 << "\n";

    return 0;
}
