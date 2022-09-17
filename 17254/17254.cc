#include <iostream>
#include <vector>

struct Input {
    int keyboard;
    int second;
    char key;
    friend bool operator==(Input &lhs, Input &rhs);
    friend bool operator!=(Input &lhs, Input &rhs);
    friend bool operator<(Input &lhs, Input &rhs);
    friend bool operator>(Input &lhs, Input &rhs);
};

Input tmp[1001];

void merge(std::vector<Input> &v, size_t idx_s, size_t idx_m, size_t idx_e);
void sort(std::vector<Input> &v, size_t idx_s, size_t idx_e);

int main() {
    int N, M;
    std::vector<Input> inputs;
    std::string ans;

    // freopen("input.txt", "r", stdin);

    std::cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        Input in;

        std::cin >> in.keyboard >> in.second >> in.key;
        inputs.push_back(in);
    }

    sort(inputs, 0, M);
    for (int i = 0; i < M; ++i) {
        ans.push_back(inputs[i].key);
    }

    std::cout << ans << "\n";

    return 0;
}

bool operator==(Input &lhs, Input &rhs) {
    if (lhs.keyboard != rhs.keyboard)
        return false;

    if (lhs.second != rhs.second)
        return false;

    if (lhs.key != rhs.key)
        return false;

    return true;
}

bool operator!=(Input &lhs, Input &rhs) { return !(lhs == rhs); }

bool operator<(Input &lhs, Input &rhs) {
    if (lhs.second < rhs.second)
        return true;
    if ((lhs.second == rhs.second) && (lhs.keyboard < rhs.keyboard))
        return true;
    return false;
}

bool operator>(Input &lhs, Input &rhs) {
    return ((lhs != rhs) && !(lhs < rhs));
}

void merge(std::vector<Input> &v, size_t idx_s, size_t idx_m, size_t idx_e) {
    size_t i, j, pos;

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

void sort(std::vector<Input> &v, size_t idx_s, size_t idx_e) {
    int idx_m = idx_s + (idx_e - idx_s) / 2;

    if ((idx_e - idx_s) < 2)
        return;

    sort(v, idx_s, idx_m);
    sort(v, idx_m, idx_e);
    merge(v, idx_s, idx_m, idx_e);
}
