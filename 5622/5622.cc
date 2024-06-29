#include <array>
#include <iostream>

constexpr size_t NUM_WORDS = 8;

int
main ()
{
  const std::array<std::string, NUM_WORDS> n_words
      = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
  size_t elapsed = 0;
  std::string word;

  // freopen("input.txt", "r", stdin);
  std::cin >> word;
  for (char letter : word) {
    for (size_t i = 0; i < NUM_WORDS; ++i) {
      if (n_words[i].find (letter) != std::string::npos) {
        elapsed += (i + 3);
        break;
      }
    }
  }

  std::cout << elapsed << "\n";
  return 0;
}
