#include <iostream>

int main() {
    std::string e_word;
    std::string d_word;

    // freopen("input.txt", "r", stdin);
    std::cin >> e_word;
    for (char l : e_word) {

        switch (l) {
        case 'A':
            d_word += 'X';
            break;
        case 'B':
            d_word += 'Y';
            break;
        case 'C':
            d_word += 'Z';
            break;
        default:
            d_word += l - 3;
            break;
        }
    }

    std::cout << d_word << "\n";

    return 0;
}
