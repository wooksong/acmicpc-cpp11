#include <iostream>
#include <regex>

int
main ()
{
  int T;
  std::regex r (R"((^[A-F]{0,1})(A{1,})(F{1,})(C{1,})([A-F]{0,1}))");

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  // freopen("input.txt", "r", stdin);

  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    std::string seq;

    std::cin >> seq;
    if (std::regex_match (seq, r)) {
      std::cout << "Infected!\n";
    } else {
      std::cout << "Good\n";
    }
  }
  return 0;
}
