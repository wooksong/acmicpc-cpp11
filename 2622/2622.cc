#include <iostream>

int main() {
    int n;
    int num_triangles = 0;
    int upper_bound_c;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;

    upper_bound_c = n >> 1;
    for (int c = 1; c <= upper_bound_c; ++c) {
        int rem = n - c;
        int upper_bound_a;

        if (rem < c)
            continue;

        upper_bound_a = rem >> 1;
        for (int a = 1; a <= upper_bound_a; ++a) {
            int b = rem - a;

            if (b <= c && a <= c && a + b > c) {
                num_triangles++;
            }
        }
    }

    std::cout << num_triangles << "\n";

    return 0;
}
