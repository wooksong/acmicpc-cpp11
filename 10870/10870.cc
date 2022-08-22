#include <iostream>
#include <vector>

uint32_t get_nth_fibo(uint32_t n, std::vector<uint32_t> &fibo);

int main() {
    uint32_t n, num;
    std::vector<uint32_t> fibo;

    std::cin >> n;
    fibo = std::vector<uint32_t>(n + 1, 0);
    num = get_nth_fibo(n, fibo);

    std::cout << num << "\n";

    return 0;
}

uint32_t get_nth_fibo(uint32_t n, std::vector<uint32_t> &fibo) {
    uint32_t ret;
    if (n == 0) {
        ret = 0;
    } else if (n == 1) {
        ret = 1;
    } else {
        ret = get_nth_fibo(n - 2, fibo) + get_nth_fibo(n - 1, fibo);
    }

    fibo[n] = ret;
    return fibo[n];
}
