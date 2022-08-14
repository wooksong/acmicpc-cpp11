#include <iostream>

int main() {
    uint32_t year;

    std::cin >> year;

    if ((year % 400) == 0) {
        printf("1\n");
        return 0;
    }
    else if ((year % 4) == 0)
    {
        if ((year % 100) != 0) {
            printf("1\n");
            return 0;
        }
    }

    printf("0\n");

    return 0;
}
