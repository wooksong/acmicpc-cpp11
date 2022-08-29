#include <iostream>

std::string to_str(int32_t m_id);
int main() {
    int32_t N, i, cnt;

    std::cin >> N;
    cnt = 0;
    for (i = 666; cnt < N; ++i) {
        std::string num = to_str(i);
        if (num.find("666") == std::string::npos)
            continue;
        cnt++;
    }

    std::cout << i - 1 << "\n";

    return 0;
}

std::string to_str(int32_t m_id) {
    int32_t b = 10;
    std::string str_num, str_num_ret;

    while (m_id != 0) {
        int32_t d = m_id % b;

        str_num.push_back(static_cast<char>(d + '0'));
        m_id /= b;
    }

    for (auto iter = str_num.rbegin(); iter != str_num.rend(); ++iter) {
        str_num_ret.push_back(*iter);
    }

    return str_num_ret;
}
