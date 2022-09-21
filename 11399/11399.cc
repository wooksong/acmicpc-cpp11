#include <iostream>

constexpr int MAX_NUM_PERSONS = 1001;
int tmp_arr[MAX_NUM_PERSONS];
int persons[MAX_NUM_PERSONS];

void merge(int *arr, int idx_s, int idx_m, int idx_e);
void sort(int *arr, int idx_s, int idx_e);

int main() {
    int N;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> persons[i];
    }

    sort(persons, 0, N);
    {
        int total;
        int sums[MAX_NUM_PERSONS] = {
            0,
        };

        sums[0] = persons[0];
        total = sums[0];
        for (int i = 1; i < N; ++i) {
            sums[i] = (persons[i] + sums[i - 1]);
            total += sums[i];
        }

        std::cout << total << "\n";
    }

    return 0;
}

void merge(int *arr, int idx_s, int idx_m, int idx_e) {
    int i, j, pos;

    i = idx_s;
    pos = idx_s;
    j = idx_m;

    while (i < idx_m && j < idx_e) {
        if (arr[i] <= arr[j]) {
            tmp_arr[pos++] = arr[i++];
        } else {
            tmp_arr[pos++] = arr[j++];
        }
    }

    while (i < idx_m) {
        tmp_arr[pos++] = arr[i++];
    }

    while (j < idx_e) {
        tmp_arr[pos++] = arr[j++];
    }

    for (i = idx_s; i < idx_e; ++i) {
        arr[i] = tmp_arr[i];
    }
}

void sort(int *arr, int idx_s, int idx_e) {
    int idx_m;

    if ((idx_e - idx_s) == 1)
        return;

    idx_m = idx_s + (idx_e - idx_s) / 2;

    sort(arr, idx_s, idx_m);
    sort(arr, idx_m, idx_e);
    merge(arr, idx_s, idx_m, idx_e);
}
