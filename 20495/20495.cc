#include <algorithm>
#include <iostream>
#include <vector>

struct NumInRange {
    int lower;
    int upper;

    NumInRange() {
        lower = INT32_MAX;
        upper = INT32_MIN;
    };
};

size_t bianry_search_min(std::vector<NumInRange> &v, size_t idx_s, size_t idx_e,
                         int val);

size_t bianry_search_max(std::vector<NumInRange> &v, size_t idx_s, size_t idx_e,
                         int val);

int main() {
    std::vector<NumInRange> nums;
    std::vector<NumInRange> sorted_lower;
    std::vector<NumInRange> sorted_upper;
    size_t N;

    // freopen("input.txt", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N;

    nums = std::vector<NumInRange>(N);
    for (size_t i = 0; i < N; ++i) {
        int num;
        int range;

        std::cin >> num >> range;

        nums[i].lower = num - range;
        nums[i].upper = num + range;
    }

    struct {
        bool operator()(NumInRange &lhs, NumInRange &rhs) {
            if (lhs.lower == rhs.lower)
                return lhs.upper < rhs.upper;
            return lhs.lower < rhs.lower;
        }
    } LowerComp;

    struct {
        bool operator()(NumInRange &lhs, NumInRange &rhs) {
            if (lhs.upper == rhs.upper)
                return lhs.lower < rhs.lower;
            return lhs.upper < rhs.upper;
        }
    } UpperComp;

    sorted_lower = std::vector<NumInRange>(nums.begin(), nums.end());
    std::sort(sorted_lower.begin(), sorted_lower.end(), LowerComp);

    sorted_upper = std::vector<NumInRange>(nums.begin(), nums.end());
    std::sort(sorted_upper.begin(), sorted_upper.end(), UpperComp);

    for (size_t i = 0; i < N; ++i) {
        int l, u;
        int left, right;

        l = nums[i].lower;
        u = nums[i].upper;

        left = 0;
        right = N - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (sorted_upper[mid].upper >= l) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        std::cout << left + 1 << " ";

        left = 0;
        right = N - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (sorted_lower[mid].lower <= u) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        std::cout << right + 1 << "\n";
    }

    return 0;
}

size_t bianry_search_max(std::vector<NumInRange> &v, size_t idx_s, size_t idx_e,
                         int val) {
    size_t idx_m;

    if (idx_s >= idx_e) {
        if (v[idx_s].lower <= val && v[idx_s].upper >= val)
            return idx_s;
        return SIZE_MAX;
    }

    idx_m = (idx_s + idx_e) / 2;
    if (v[idx_m].lower <= val && v[idx_m].upper >= val) {
        size_t idx = bianry_search_max(v, idx_m + 1, idx_e, val);

        if (idx == SIZE_MAX) {
            return idx_m;
        }
        return std::max(idx_m, idx);
    } else if (v[idx_m].lower <= val) {
        return bianry_search_max(v, idx_m + 1, idx_e, val);
    } else if (v[idx_m].lower > val) {
        return bianry_search_max(v, idx_s, idx_m, val);
    }

    return SIZE_MAX;
}

size_t bianry_search_min(std::vector<NumInRange> &v, size_t idx_s, size_t idx_e,
                         int val) {
    size_t idx_m;

    if (idx_s >= idx_e) {
        if (v[idx_s].lower <= val && v[idx_s].upper >= val)
            return idx_s;
        return SIZE_MAX;
    }

    idx_m = (idx_s + idx_e) / 2;
    if (v[idx_m].lower <= val && v[idx_m].upper >= val) {
        size_t idx = bianry_search_min(v, idx_s, idx_m, val);

        if (idx == SIZE_MAX) {
            return idx_m;
        }
        return std::min(idx_m, idx);
    } else if (v[idx_m].lower <= val) {
        return bianry_search_min(v, idx_m + 1, idx_e, val);
    } else if (v[idx_m].lower > val) {
        return bianry_search_min(v, idx_s, idx_m, val);
    }

    return SIZE_MAX;
}
