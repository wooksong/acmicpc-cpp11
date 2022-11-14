#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> skill_levels;
    size_t num_teams;
    int num_students;

    freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> num_students;
    skill_levels = std::vector<int>(num_students);

    for (int i = 0; i < num_students; ++i) {
        std::cin >> skill_levels[i];
    }

    std::sort(skill_levels.begin(), skill_levels.end());

    num_teams = 0;
    for (int i = 0; i < num_students - 2; ++i) {
        for (int j = i + 1; j < num_students - 1; ++j) {
            int goal = -(skill_levels[i] + skill_levels[j]);
            size_t lb = std::lower_bound(skill_levels.begin() + j + 1,
                                         skill_levels.end(), goal) -
                        skill_levels.begin();
            size_t ub = std::upper_bound(skill_levels.begin() + j + 1,
                                         skill_levels.end(), goal) -
                        skill_levels.begin();

            num_teams += (ub - lb);
        }
    }

    std::cout << num_teams << "\n";

    return 0;
}
