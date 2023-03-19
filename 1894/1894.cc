#include <bitset>
#include <iostream>
#include <vector>

constexpr size_t NUM_POINTS_GIVEN = 4;
constexpr size_t NUM_EDGES_GIVEN = NUM_POINTS_GIVEN - 1;
constexpr double INVALID_VAL = 100001;

struct Point {
    Point() {
        this->x = INVALID_VAL;
        this->y = INVALID_VAL;
    };

    Point(const Point &p) {
        this->x = p.x;
        this->y = p.y;
    };

    Point(double dx, double dy) {
        this->x = dx;
        this->y = dy;
    };

    Point operator-(Point &rhs) {
        return Point(this->x - rhs.x, this->y - rhs.y);
    };

    bool operator==(Point &rhs) {
        if (this->x == rhs.x && this->y == rhs.y) {
            return true;
        }

        return false;
    }

    Point &operator=(const Point &rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        return *this;
    }

    double x;
    double y;
};

int main() {
    std::vector<Point> points;
    double x, y;
    int cnt;

    // freopen("input.txt", "r", stdin);
    std::cout << std::fixed;
    std::cout.precision(3);

    cnt = 0;
    while (std::cin >> x && std::cin >> y) {
        Point pivot;
        Point first;
        Point second;

        points.push_back(Point(x, y));
        cnt++;

        if (cnt == NUM_POINTS_GIVEN) {
            std::bitset<NUM_POINTS_GIVEN> flag_pivot_points;

            for (size_t i = 0; i < NUM_EDGES_GIVEN; ++i) {
                for (size_t j = i + 1; j < NUM_POINTS_GIVEN; ++j) {
                    if (points[i] == points[j]) {
                        flag_pivot_points.reset();
                        flag_pivot_points.set(i);
                        flag_pivot_points.set(j);
                        i = NUM_POINTS_GIVEN;
                        break;
                    }
                }
            }

            for (size_t i = 0; i < NUM_POINTS_GIVEN; ++i) {
                if (flag_pivot_points.test(i)) {
                    pivot = points[i];
                } else {
                    if (first.x == INVALID_VAL) {
                        first = points[i];
                    } else {
                        second = points[i];
                    }
                }
            }
            {
                Point diff = pivot - first;
                Point p = second - diff;

                std::cout << p.x << " " << p.y << "\n";
            }

            points.clear();
            cnt = 0;
        }
    }

    return 0;
}
