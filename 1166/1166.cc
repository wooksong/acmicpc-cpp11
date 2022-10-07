#include <cmath>
#include <iostream>

using lli = long long int;

struct Square {
    lli l;
    lli w;
    lli h;

    double get_possible_boxes(double len) {
        return std::floor(l / len) * std::floor(w / len) * std::floor(h / len);
    }
};

double binary_search(double n, double s, double e, Square &sqr);

int main() {
    Square sqr;
    lli N;
    double val_s, val_e, val_m;

    // freopen("input.txt", "r", stdin);

    std::cin >> N >> sqr.l >> sqr.w >> sqr.h;
    val_s = 0;
    val_e = 2e10;
    for (int i = 0; i < 1000; ++i) {
        val_m = (val_s + val_e) / 2;

        if (sqr.get_possible_boxes(val_m) < N) {
            val_e = val_m;
        } else {
            val_s = val_m;
        }
    }

    printf("%.10lf\n", val_e);

    return 0;
}
