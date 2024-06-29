#include <iostream>
#include <memory.h>

using namespace std;

constexpr int WORD_LIMIT = 101;

int
main ()
{
  char word[WORD_LIMIT];

  memset (word, '\0', WORD_LIMIT);
  cin >> word;

  for (uint32_t i = 0;; ++i) {
    if (word[i] == '\0') {
      printf ("%u\n", i);
      break;
    }
  }

  return 0;
}
