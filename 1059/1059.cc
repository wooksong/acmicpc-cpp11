#include <algorithm>
#include <iostream>
#include <vector>

int binary_search(std::vector<int> &arr, int s, int e, int num);

int main() {
    int l, n, cnt, lower_limit, upper_limit;
    std::vector<int> S;

    // freopen("input.txt", "r", stdin);

    std::cin >> l;
    S = std::vector<int>(l);

    for (int i = 0; i < l; ++i) {
        std::cin >> S[i];
    }

    std::sort(S.begin(), S.end());
    std::cin >> n;

    lower_limit = binary_search(S, 0, l, n);
    upper_limit = lower_limit + 1;

    cnt = 0;
    for (int i = S[lower_limit] + 1; i <= n; ++i) {
        for (int j = S[upper_limit] - 1; j >= n; --j) {
            if (i == j)
                continue;
            cnt++;
        }
    }

    std::cout << ((cnt == 0) ? -1 : cnt) << "\n";
    return 0;
}

int binary_search(std::vector<int> &arr, int s, int e, int num) {
    int m;

    if ((s + 1) == e) {
        return s;
    }
    m = (e - s) / 2 + s;

    if (arr[m] > num) {
        return binary_search(arr, s, m, num);
    } else {
        return binary_search(arr, m, e, num);
    }
}
