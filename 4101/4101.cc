#include <iostream>

int main () {

    // freopen("input.txt", "r", stdin);

    for (;;) {
        uint32_t numl, numr;

        std::cin >> numl >> numr;

        if ((numl == 0) && (numr == 0))
            break;

        if (numl > numr) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
