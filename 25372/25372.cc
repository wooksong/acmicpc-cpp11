#include <iostream>

int
main ()
{
  std::string password;
  int nums_str;

  // freopen("input.txt", "r", stdin);
  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);
  std::cin >> nums_str;
  for (int i = 0; i < nums_str; ++i) {
    std::string ans;
    size_t len;

    std::cin >> password;
    len = password.length ();
    if (len < 6U || len > 9U) {
      ans = "no\n";
    } else {
      ans = "yes\n";
    }

    std::cout << ans;
  }

  return 0;
}
