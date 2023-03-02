#include <iostream>
#include <unordered_map>

constexpr int NUM_SUBJECTS = 20;

int main() {
    std::unordered_map<std::string, double> dict = {
        {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5},
        {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0.0},
    };
    double gpa;
    double total_credits;

    // freopen("input.txt", "r", stdin);

    gpa = 0;
    total_credits = 0;
    for (int i = 0; i < NUM_SUBJECTS; ++i) {
        std::string name_subject;
        std::string grade;
        double credits;

        std::cin >> name_subject >> credits >> grade;

        if (grade == "P")
            continue;

        total_credits += credits;
        gpa += (credits * dict[grade]);
    }

    std::cout << gpa / total_credits << "\n";

    return 0;
}
