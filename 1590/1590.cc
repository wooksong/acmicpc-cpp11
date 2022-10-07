#include <iostream>
#include <vector>

std::vector<int> time_table;
std::vector<int> tmp;

void binary_search(int idx_s, int idx_e, int val, int &wtime);
void merge(size_t idx_s, size_t idx_m, size_t idx_e);
void sort(size_t idx_s, size_t idx_e);

int main() {
    int num_buses;
    int arrival;
    int min_wtime = INT32_MAX;
    int len_time_tbl;

    // freopen("input.txt", "r", stdin);
    std::cin >> num_buses >> arrival;

    len_time_tbl = 0;
    for (int i = 0; i < num_buses; ++i) {
        int s_time, step, num;

        std::cin >> s_time >> step >> num;

        for (int j = 0; j < num; ++j) {
            time_table.push_back(s_time + step * j);
            len_time_tbl++;
        }
    }

    tmp = std::vector<int>(len_time_tbl);

    sort(0, len_time_tbl);
    binary_search(0, len_time_tbl, arrival, min_wtime);
    std::cout << (min_wtime != INT32_MAX ? min_wtime : -1) << "\n";

    return 0;
}

void merge(size_t idx_s, size_t idx_m, size_t idx_e) {
    size_t i, j, pos;

    i = idx_s;
    j = idx_m;
    pos = idx_s;

    while (i < idx_m && j < idx_e) {
        if (time_table[i] < time_table[j]) {
            tmp[pos++] = time_table[i++];
        } else {
            tmp[pos++] = time_table[j++];
        }
    }

    while (i < idx_m) {
        tmp[pos++] = time_table[i++];
    }
    while (j < idx_e) {
        tmp[pos++] = time_table[j++];
    }

    for (i = idx_s; i < idx_e; ++i) {
        time_table[i] = tmp[i];
    }
}
void sort(size_t idx_s, size_t idx_e) {
    size_t idx_m;

    if ((idx_e - idx_s) < 2)
        return;

    idx_m = (idx_e - idx_s) / 2 + idx_s;
    sort(idx_s, idx_m);
    sort(idx_m, idx_e);
    merge(idx_s, idx_m, idx_e);
}

void binary_search(int idx_s, int idx_e, int val, int &wtime) {
    int idx_m;

    if (idx_s > idx_e)
        return;

    idx_m = (idx_s + idx_e) / 2;
    if (time_table[idx_m] >= val) {
        int lwt = time_table[idx_m] - val;
        wtime = std::min(wtime, lwt);
        binary_search(idx_s, idx_m - 1, val, wtime);
    } else {
        binary_search(idx_m + 1, idx_e, val, wtime);
    }
}
