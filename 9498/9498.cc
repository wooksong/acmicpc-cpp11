#include <iostream>

int
main ()
{
  uint32_t score = 0;

  std::cin >> score;
  if (score >= 90) {
    printf ("A\n");
  } else if (score >= 80) {
    printf ("B\n");
  } else if (score >= 70) {
    printf ("C\n");
  } else if (score >= 60) {
    printf ("D\n");
  } else {
    printf ("F\n");
  }

  return 0;
}
