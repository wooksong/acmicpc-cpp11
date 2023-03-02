#include <bitset>
#include <iostream>
#include <vector>

constexpr size_t NUM_CLASSES = 9;
constexpr size_t NUM_SCHOOL_YEARS = 5;

using fields_class = std::bitset<NUM_CLASSES * NUM_SCHOOL_YEARS>;

int main() {
    std::vector<fields_class> students_info;
    size_t num_students;
    size_t max_num_classmates;
    size_t tmp_cap = SIZE_MAX;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> num_students;

    students_info = std::vector<fields_class>(num_students);

    for (size_t i = 0; i < num_students; ++i) {
        students_info[i].reset();
        for (size_t j = 0; j < NUM_SCHOOL_YEARS; ++j) {
            size_t c;

            std::cin >> c;
            students_info[i].set(c - 1 + (j * NUM_CLASSES));
        }
    }

    max_num_classmates = 0;
    for (size_t i = 0; i < num_students; ++i) {
        size_t num_classmates = 0;

        for (size_t j = 0; j < num_students; ++j) {
            fields_class each;
            if (i == j)
                continue;
            each = students_info[i] & students_info[j];
            if (each != 0) {
                num_classmates++;
            }
        }

        if (num_classmates > max_num_classmates) {
            max_num_classmates = num_classmates;
            tmp_cap = i + 1;
        }
    }

    std::cout << (tmp_cap != SIZE_MAX ? tmp_cap : 1) << "\n";

    return 0;
}
