#include <iostream>

int
main ()
{
  int num_z_streaks = 0;
  int num_o_streaks = 0;
  bool is_zero = false;
  std::string S;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  // freopen("input.txt", "r", stdin);

  std::cin >> S;

  if (S[0] == '0') {
    is_zero = true;
  }

  for (size_t i = 1; i < S.length (); ++i) {
    if ((is_zero) && (S[i] == '1')) {
      is_zero = false;
      ++num_z_streaks;
    } else if ((!is_zero) && S[i] == '0') {
      is_zero = true;
      ++num_o_streaks;
    }
  }

  if ((!num_o_streaks) && (!num_z_streaks)) {
    std::cout << "0\n";
  } else if (num_o_streaks == num_z_streaks) {
    std::cout << num_o_streaks << "\n";
  } else {
    std::cout << std::min (num_o_streaks, num_z_streaks) + 1 << "\n";
  }

  return 0;
}
