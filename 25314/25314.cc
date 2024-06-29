#include <iostream>

constexpr int WORD = 4;

int
main ()
{
  int num_bytes;
  int num_words;

  // freopen("input.txt", "r", stdin);

  std::cin >> num_bytes;
  num_words = num_bytes / WORD;

  for (int i = 0; i < num_words; ++i) {
    std::cout << "long ";
  }

  std::cout << "int\n";

  return 0;
}
