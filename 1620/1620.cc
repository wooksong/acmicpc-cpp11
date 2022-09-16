#include <iostream>
#include <vector>

constexpr int MAX_NUM_POKEMONS = 100001;

int gen_hash(std::string &name);

int main() {
    std::vector<std::string> pokemons_by_number;
    std::vector<int> pokemons_by_hash[MAX_NUM_POKEMONS];
    int N, M;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        std::string name;
        std::vector<int> *v;

        std::cin >> name;
        pokemons_by_number.push_back(name);
        v = &pokemons_by_hash[gen_hash(name) % MAX_NUM_POKEMONS];
        v->push_back(i);
    }

    for (int i = 0; i < M; ++i) {
        std::string quiz;

        std::cin >> quiz;

        if ((quiz[0] >= '0') && (quiz[0] <= '9')) {
            int mul = 1;
            int num = 0;
            for (auto iter = quiz.rbegin(); iter != quiz.rend();
                 ++iter, mul *= 10) {
                int digit = static_cast<int>(*iter - '0');
                num = num + digit * mul;
            }
            std::cout << pokemons_by_number[num - 1] << "\n";
        } else {
            std::vector<int> *v =
                &pokemons_by_hash[gen_hash(quiz) % MAX_NUM_POKEMONS];
            for (auto iter = v->begin(); iter != v->end(); ++iter) {
                if (pokemons_by_number[*iter] == quiz) {
                    std::cout << *iter + 1 << "\n";
                }
            }
        }
    }
    return 0;
}

int gen_hash(std::string &name) {
    const int mul = 37;
    const int dividor = 100003;

    int hash = 0;
    int m = 1;
    for (auto iter = name.begin(); iter != name.end(); ++iter, m *= mul) {
        m %= dividor;
        if (*iter < 'a') {
            hash += (((static_cast<int>(*iter - 'A') + 1) * m) % dividor);
        } else {
            hash += (((static_cast<int>(*iter - 'a') + 1) * m) % dividor);
        }
        hash %= dividor;
    }

    return hash;
}
