#include <iostream>

int
main ()
{
  int N;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  while (true) {
    std::string num_str;
    std::cin >> N;

    if (N == 0)
      break;

    while (N >= 10) {
      int tmp;

      num_str = std::to_string (N);

      tmp = 0;
      for (auto c = num_str.begin (); c != num_str.end (); ++c) {
        tmp += static_cast<int> (*c - '0');
      }

      N = tmp;
    }

    std::cout << N << "\n";
  }
  return 0;
}
