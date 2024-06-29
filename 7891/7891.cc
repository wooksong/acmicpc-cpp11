#include <iostream>

int
main ()
{
  int T;
  int l, r;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> T;
  while (T--) {
    std::cin >> l >> r;

    std::cout << l + r << "\n";
  }

  return 0;
}
