#include <iostream>
#include <vector>

constexpr size_t MAX_NUM_USERS = 1000000;
std::vector<int> users(MAX_NUM_USERS);

int find(int x);
void make_union(int x, int y);

int main() {
    int num_tcs;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    std::cin >> num_tcs;
    for (int t = 1; t <= num_tcs; ++t) {
        int num_users;
        int num_relations;
        int num_cases;

        std::cin >> num_users;
        std::cin >> num_relations;

        for (int i = 0; i < num_users; ++i) {
            users[i] = i;
        }

        for (int i = 0; i < num_relations; ++i) {
            int f, l;

            std::cin >> f;
            std::cin >> l;

            make_union(f, l);
        }

        std::cout << "Scenario " << t << ":\n";
        std::cin >> num_cases;

        for (int i = 0; i < num_cases; ++i) {
            int case_f, case_l;

            std::cin >> case_f;
            std::cin >> case_l;

            std::cout << (find(case_f) == find(case_l) ? "1" : "0");

            std::cout << "\n";
        }

        std::cout << "\n";
    }

    return 0;
}

int find(int x) {
    int c = x;

    while (users[c] != c) {
        c = users[c];
    }

    return c;
}

void make_union(int x, int y) {
    int px = find(x);
    int py = find(y);

    users[py] = px;
}
