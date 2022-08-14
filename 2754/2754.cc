#include <iostream>

int main() {
    std::string score;

    std::cin >> score;
    if (score == "A+") {
        printf("4.3\n");
    } else if (score == "A0") {
        printf("4.0\n");
    } else if (score == "A-") {
        printf("3.7\n");
    }else if (score == "B+") {
        printf("3.3\n");
    }else if (score == "B0") {
        printf("3.0\n");
    }else if (score == "B-") {
        printf("2.7\n");
    }else if (score == "C+") {
        printf("2.3\n");
    }else if (score == "C0") {
        printf("2.0\n");
    }else if (score == "C-") {
        printf("1.7\n");
    }else if (score == "D+") {
        printf("1.3\n");
    }else if (score == "D0") {
        printf("1.0\n");
    } else if (score == "D-") {
        printf("0.7\n");
    } else {
        printf("0.0\n");
    }

    return 0;
}
