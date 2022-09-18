#include <iostream>
#include <vector>

constexpr int MAX_N = 1000001;

struct Coord {
    int val_x;
    int o_idx;

    friend bool operator==(Coord &lhs, Coord &rhs);
    friend bool operator!=(Coord &lhs, Coord &rhs);
    friend bool operator<(Coord &lhs, Coord &rhs);
    friend bool operator>(Coord &lhs, Coord &rhs);
};

bool operator==(Coord &lhs, Coord &rhs) {
    if ((lhs.val_x == rhs.val_x) && (lhs.o_idx == rhs.o_idx))
        return true;
    return false;
}

bool operator!=(Coord &lhs, Coord &rhs) { return !(lhs == rhs); }

bool operator<(Coord &lhs, Coord &rhs) {
    if (lhs == rhs)
        return false;
    if (lhs.val_x < rhs.val_x)
        return true;
    return false;
}

bool operator>(Coord &lhs, Coord &rhs) {
    return ((lhs != rhs) && (lhs.val_x > rhs.val_x));
}

void merge(std::vector<Coord> &v, int idx_s, int idx_m, int idx_e);
void sort(std::vector<Coord> &v, int idx_s, int idx_e);

Coord tmp[MAX_N];

int main() {
    int N;
    int prev;
    int i;
    int ans[MAX_N];
    std::vector<Coord> points;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    std::cin >> N;
    points = std::vector<Coord>(N);

    for (i = 0; i < N; ++i) {
        std::cin >> points[i].val_x;
        points[i].o_idx = i;
    }

    sort(points, 0, N);

    prev = INT32_MIN;
    i = -1;
    for (auto iter = points.begin(); iter != points.end(); ++iter) {
        if ((*iter).val_x != prev) {
            ++i;
        }

        ans[(*iter).o_idx] = i;
        prev = (*iter).val_x;
    }

    for (i = 0; i < N; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

void merge(std::vector<Coord> &v, int idx_s, int idx_m, int idx_e) {
    int i, j, pos;

    i = idx_s;
    j = idx_m;
    pos = idx_s;

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

void sort(std::vector<Coord> &v, int idx_s, int idx_e) {
    int idx_m;

    if ((idx_e - idx_s) == 1)
        return;

    idx_m = idx_s + (idx_e - idx_s) / 2;

    sort(v, idx_s, idx_m);
    sort(v, idx_m, idx_e);
    merge(v, idx_s, idx_m, idx_e);
}
