#include <algorithm>
#include <iostream>
#include <vector>

struct Point {
    int32_t x;
    int32_t y;

    Point() {
        this->x = 0;
        this->y = 0;
    }

    Point(int32_t x, int32_t y) {
        this->x = x;
        this->y = y;
    }

    void dump() { std::cout << this->x << " " << this->y << "\n"; }
    friend bool operator<(Point l, Point r);
    friend bool operator>(Point l, Point r);
    friend bool operator==(Point l, Point r);
};

int main() {
    size_t N;
    std::vector<Point> points = std::vector<Point>();

    // freopen("input.txt", "r", stdin);
    std::cin >> N;
    for (size_t i = 0; i < N; ++i) {
        int32_t x, y;
        Point p;

        std::cin >> x >> y;
        p = Point(x, y);
        points.push_back(p);
    }

    std::sort(points.begin(), points.end());
    for (auto &p : points) {
        p.dump();
    }

    return 0;
}

bool operator<(Point l, Point r) {
    if (l.x < r.x)
        return true;
    if (l.x == r.x)
        return (l.y < r.y);
    return false;
}

bool operator>(Point l, Point r) { return !(l < r); }
bool operator==(Point l, Point r) { return l.x == r.x && l.y == r.y; }
