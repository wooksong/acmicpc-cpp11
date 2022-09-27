#include <iostream>

void visit(int n, int row, int col, int r, int c);

int main() {
    int N, r, c;

    // freopen("input.txt", "r", stdin);
    std::cin >> N >> r >> c;
    visit(2 << N, 0, 0, r, c);
    return 0;
}

void visit(int n, int row, int col, int r, int c) {
    static int v = 0;

    if (n == 2) {
        int urow = row + 2;
        int ucol = col + 2;

        if (row <= r && r < urow && col <= c && c < ucol) {
            for (int i = row; i < urow; ++i) {
                for (int j = col; j < ucol; ++j) {
                    if (i == r && j == c)
                        std::cout << v << "\n";
                    v++;
                }
            }
        } else {
            v += 4;
        }

        return;
    }
    n >>= 1;

    if ((row <= r && r < row + n) && (col <= c && c < col + n)) {
        v = v;
        visit(n, row, col, r, c);
    } else if ((row <= r && r < row + n) && (col + n <= c && c < col + 2 * n)) {
        v += (n * n);
        visit(n, row, col + n, r, c);
    } else if ((row + n <= r && r < row + 2 * n) && (col <= c && c < col + n)) {
        v += (2 * n * n);
        visit(n, row + n, col, r, c);
    } else if ((row + n <= r && r < row + 2 * n) &&
               (col + n <= c && c < col + 2 * n)) {
        v += (3 * n * n);
        visit(n, row + n, col + n, r, c);
    }
}
