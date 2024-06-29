#include <iostream>
#include <memory.h>

constexpr int NUM_ALPHABET = 26;
constexpr int MAXLEN_STR = 101;

int
main ()
{
  int alphabet[NUM_ALPHABET];
  char in_str[MAXLEN_STR];

  for (int i = 0; i < NUM_ALPHABET; ++i) {
    alphabet[i] = -1;
  }
  memset (in_str, '\0', MAXLEN_STR);

  std::cin >> in_str;

  for (int i = 0; i < MAXLEN_STR; ++i) {
    int idx;

    if (in_str[i] == '\0')
      break;
    idx = in_str[i] - 'a';

    if (alphabet[idx] == -1) {
      alphabet[idx] = i;
    }
  }

  for (int i = 0; i < NUM_ALPHABET; ++i) {
    printf ("%d ", alphabet[i]);
  }

  return 0;
}
