#include <cmath>
#include <iostream>

int main() {
    uint32_t N;
    long double f_num = 1;

    std::cin >> N;
    f_num = pow(0.5, static_cast<long double>(N));

    printf("%.*Lf\n", N, f_num);
    return 0;
}
