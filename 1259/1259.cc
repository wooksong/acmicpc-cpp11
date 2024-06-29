#include <iostream>

int
main ()
{
  std::string in_num;
  size_t len, len_half;
  bool is_palindrome;

  // freopen("input.txt", "r", stdin);
  while (true) {
    std::cin >> in_num;
    if (in_num == "0")
      break;
    is_palindrome = true;
    len = in_num.length ();
    len_half = in_num.length () / 2;

    for (size_t idx = 0; idx <= len_half; ++idx) {
      if (in_num.at (idx) != in_num.at (len - 1 - idx)) {
        is_palindrome = false;
        break;
      }
    }

    if (is_palindrome)
      std::cout << "yes\n";
    else
      std::cout << "no\n";
  }

  return 0;
}
