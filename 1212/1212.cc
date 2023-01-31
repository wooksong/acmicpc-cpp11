#include <iostream>
#include <unordered_map>

std::unordered_map<char, std::string> lookup_table = {
    {'0', "000"}, {'1', "001"}, {'2', "010"}, {'3', "011"},
    {'4', "100"}, {'5', "101"}, {'6', "110"}, {'7', "111"},
};

int main() {
    std::string octal;
    std::string binary;
    size_t pos;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> octal;
    for (auto iter = octal.begin(); iter != octal.end(); ++iter) {
        binary.append(lookup_table[*iter]);
    }

    pos = binary.find_first_not_of('0');

    if (pos != std::string::npos) {
        binary = binary.substr(pos);
    } else {
        binary = "0";
    }

    std::cout << binary << "\n";

    return 0;
}
