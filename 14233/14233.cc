#include <iostream>
#include <vector>

constexpr int MAX_NUM_WORKS = 50001;

int tmp[MAX_NUM_WORKS];

void merge(std::vector<int> &v, int idx_s, int idx_m, int idx_e);
void sort(std::vector<int> &v, int idx_s, int idx_e);

int main() {
    std::vector<int> deadlines;
    int num_works;
    int longest_wh;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> num_works;

    deadlines = std::vector<int>(num_works);
    for (int i = 0; i < num_works; ++i) {
        std::cin >> deadlines[i];
    }

    sort(deadlines, 0, num_works);
    longest_wh = deadlines[0];
    for (int i = 1; i < num_works; ++i) {
        int ith_wh = (i + 1) * longest_wh;

        if (ith_wh > deadlines[i]) {
            longest_wh = deadlines[i] / (i + 1);
        }
    }

    std::cout << longest_wh << "\n";
    return 0;
}

void merge(std::vector<int> &v, int idx_s, int idx_m, int idx_e) {
    int i, j, pos;

    i = idx_s;
    pos = idx_s;
    j = idx_m;

    while (i < idx_m && j < idx_e) {
        if (v[i] < v[j]) {
            tmp[pos++] = v[i++];
        } else {
            tmp[pos++] = v[j++];
        }
    }

    while (i < idx_m) {
        tmp[pos++] = v[i++];
    }

    while (j < idx_e) {
        tmp[pos++] = v[j++];
    }

    for (i = idx_s; i < idx_e; ++i) {
        v[i] = tmp[i];
    }
}

void sort(std::vector<int> &v, int idx_s, int idx_e) {
    int idx_m;

    if ((idx_e - idx_s) < 2)
        return;

    idx_m = idx_s + (idx_e - idx_s) / 2;

    sort(v, idx_s, idx_m);
    sort(v, idx_m, idx_e);
    merge(v, idx_s, idx_m, idx_e);
}
