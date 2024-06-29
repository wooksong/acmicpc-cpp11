#include <iostream>

constexpr int MAXLEN = 101;

int
main ()
{
  char line[MAXLEN];

  // freopen("input.txt", "r", stdin);
  while (std::cin.getline (line, MAXLEN, '\n')) {
    printf ("%s\n", line);
  }

  return 0;
}
