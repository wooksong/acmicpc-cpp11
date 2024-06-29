#include <iostream>

constexpr int MAX_WORD_LEN = 101;

int
main ()
{
  const uint8_t diff = 'a' - 'A';
  char word[MAX_WORD_LEN];

  std::cin >> word;
  for (uint32_t i = 0; i < MAX_WORD_LEN; ++i) {
    if (word[i] == '\0')
      break;
    else if (word[i] >= 'a')
      printf ("%c", word[i] - diff);
    else
      printf ("%c", word[i] + diff);
  }
  printf ("\n");

  return 0;
}
