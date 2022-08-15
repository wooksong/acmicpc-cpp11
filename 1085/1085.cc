#include <iostream>

int main() {
    int32_t x, y, w, h, min;

    std::cin >> x >> y >> w >> h;
    min = w - x;
    if (min > x) {
        min = x;
    }

    if (min > y) {
        min = y;
    }

    if (min > (h - y)) {
        min = h - y;
    }

    printf("%d\n", min);

    return 0;
}
