#include <iostream>

int
main ()
{
  int def, antidef;
  int ans = 1;

  std::cin >> def >> antidef;

  if ((def * (100 - antidef)) >= 10000) {
    ans = 0;
  }

  std::cout << ans << "\n";

  return 0;
}
