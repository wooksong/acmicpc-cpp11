#include <iostream>
#include <vector>

int main() {
    std::string str_num;
    std::vector<uint32_t> vec_nums;

    // freopen("input.txt", "r", stdin);

    while (true) {
        std::cin >> str_num;
        if (str_num == "0")
            break;
        while (str_num.length() > 1) {
            uint32_t sum = 0;

            for (auto iter = str_num.begin(); iter != str_num.end(); ++iter) {
                vec_nums.push_back(*iter - '0');
            }
            for (uint32_t num : vec_nums) {
                sum += num;
            }
            vec_nums.clear();

            str_num = std::to_string(sum);
        }

        std::cout << str_num << "\n";
    }

    return 0;
}
