#include <iostream>
#include <vector>

constexpr size_t MAX_NUM_ELEMENTS = 51;
int tmp_arr[MAX_NUM_ELEMENTS];

void merge(std::vector<int> &arr, size_t idx_s, size_t idx_m, size_t idx_e);
void sort(std::vector<int> &arr, size_t idx_s, size_t idx_e);

int main() {
    int N, i, sum;
    std::vector<int> array_a;
    std::vector<int> array_b;

    // freopen("input.txt", "r", stdin);

    std::cin >> N;
    for (i = 0; i < N; ++i) {
        int n;

        std::cin >> n;
        array_a.push_back(n);
    }

    for (i = 0; i < N; ++i) {
        int n;

        std::cin >> n;
        array_b.push_back(n);
    }

    sort(array_a, 0, N);
    sort(array_b, 0, N);

    i = 0;
    sum = 0;
    for (auto iter = array_a.rbegin(); iter < array_a.rend(); ++iter) {
        sum += (*iter * array_b[i++]);
    }

    std::cout << sum << "\n";

    return 0;
}

void merge(std::vector<int> &arr, size_t idx_s, size_t idx_m, size_t idx_e) {
    size_t i, j, pos;

    i = idx_s;
    j = idx_m;
    pos = idx_s;

    while (i < idx_m && j < idx_e) {
        if (arr[i] < arr[j]) {
            tmp_arr[pos++] = arr[i++];
        } else {
            tmp_arr[pos++] = arr[j++];
        }
    }

    for (size_t k = i; k < idx_m; ++k) {
        tmp_arr[pos++] = arr[k];
    }

    for (size_t k = j; k < idx_e; ++k) {
        tmp_arr[pos++] = arr[k];
    }

    for (size_t k = idx_s; k < idx_e; ++k) {
        arr[k] = tmp_arr[k];
    }
}

void sort(std::vector<int> &arr, size_t idx_s, size_t idx_e) {
    int idx_m;

    if ((idx_e - idx_s) <= 1)
        return;

    idx_m = (idx_e - idx_s) / 2 + idx_s;

    sort(arr, idx_s, idx_m);
    sort(arr, idx_m, idx_e);
    merge(arr, idx_s, idx_m, idx_e);
}
