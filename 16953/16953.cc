#include <deque>
#include <iostream>

struct Integer {
    int64_t num;
    int64_t num_processed;
    bool is_visited;
    Integer() { is_visited = false; }
};

int64_t bfs(std::deque<Integer> &v, int64_t to);

int main() {
    std::deque<Integer> queue;
    int64_t from, to, ans;
    Integer init;

    // freopen("input.txt", "r", stdin);
    std::cin >> from >> to;

    init.num = from;
    init.num_processed = 1;

    queue.push_back(init);

    ans = bfs(queue, to);
    std::cout << (ans != INT64_MAX ? ans : -1) << "\n";

    return 0;
}

int64_t bfs(std::deque<Integer> &q, int64_t to) {
    int64_t ret = INT64_MAX;

    while (!q.empty()) {
        Integer popped = q.front();
        Integer num_doubled;
        Integer num_concated;

        q.pop_front();
        if (!popped.is_visited) {
            popped.is_visited = true;
            if (popped.num == to) {
                ret = std::min(ret, popped.num_processed);
                return ret;
            }
        }

        num_doubled.is_visited = false;
        num_doubled.num = popped.num << 1;
        num_doubled.num_processed = popped.num_processed + 1;
        if (num_doubled.num <= to)
            q.push_back(num_doubled);

        num_concated.is_visited = false;
        num_concated.num = popped.num * 10 + 1;
        num_concated.num_processed = popped.num_processed + 1;
        if (num_concated.num <= to)
            q.push_back(num_concated);
    }

    return ret;
}
