#include <iostream>
#include <sstream>

constexpr int NUM_LINES = 3;
constexpr int UPPER_BOUND = 23 * 3600 + 59 * 60 + 59;
constexpr int LOWER_BOUND = 0;

struct hhmmss_t {
    int hh;
    int mm;
    int ss;
    int conv_secs;
    int concat_num;

    hhmmss_t() {
        hh = -1;
        mm = -1;
        ss = -1;
        conv_secs = -1;
        concat_num = -1;
    }

    hhmmss_t(int hh, int mm, int ss) {
        this->hh = hh;
        this->mm = mm;
        this->ss = ss;

        this->conv_secs = ss + mm * 60 + hh * 3600;
        this->concat_num = ss + mm * 100 + hh * 10000;
    }

    hhmmss_t(int conv_s) {
        int hh, mm, ss;

        hh = conv_s / 3600;
        conv_s %= 3600;

        mm = conv_s / 60;
        conv_s %= 60;

        ss = conv_s;

        *this = hhmmss_t(hh, mm, ss);
    }

    bool operator==(hhmmss_t &rhs) {
        if ((this->hh == rhs.hh) && (this->mm == rhs.mm) &&
            (this->ss == rhs.ss)) {
            return true;
        }

        return false;
    }

    bool operator!=(hhmmss_t &rhs) { return !(*this == rhs); }

    bool operator<(hhmmss_t &rhs) {
        if (*this == rhs)
            return false;

        if (this->conv_secs >= rhs.conv_secs) {
            return false;
        }

        return true;
    }
};

int main() {
    std::string from, to;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for (int i = 0; i < NUM_LINES; ++i) {
        std::stringstream sstream;
        hhmmss_t from_hhmmss;
        hhmmss_t to_hhmmss;
        int hh, mm, ss;
        int cnt;
        char delimeter;

        std::cin >> from >> to;

        sstream.str(from);
        sstream >> hh >> delimeter >> mm >> delimeter >> ss;
        from_hhmmss = hhmmss_t(hh, mm, ss);

        sstream.clear();

        sstream.str(to);
        sstream >> hh >> delimeter >> mm >> delimeter >> ss;
        to_hhmmss = hhmmss_t(hh, mm, ss);

        cnt = 0;
        if (to_hhmmss.conv_secs < from_hhmmss.conv_secs) {
            hhmmss_t upper(UPPER_BOUND);
            hhmmss_t lower(LOWER_BOUND);

            for (int i = from_hhmmss.conv_secs; i <= upper.conv_secs; ++i) {
                hhmmss_t next(i);

                if (next.concat_num % 3 == 0) {
                    cnt++;
                }
            }

            for (int i = lower.conv_secs; i <= to_hhmmss.conv_secs; ++i) {
                hhmmss_t next(i);

                if (next.concat_num % 3 == 0) {
                    cnt++;
                }
            }
        } else {
            for (int i = from_hhmmss.conv_secs; i <= to_hhmmss.conv_secs; ++i) {
                hhmmss_t next(i);

                if (next.concat_num % 3 == 0) {
                    cnt++;
                }
            }
        }

        std::cout << cnt << "\n";
    }

    return 0;
}
