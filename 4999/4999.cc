#include <iostream>

int
main ()
{
  std::string longestAh;
  std::string hospitalAh;

  std::cin >> longestAh;
  std::cin >> hospitalAh;

  if (longestAh.length () < hospitalAh.length ())
    printf ("no\n");
  else
    printf ("go\n");

  return 0;
}
