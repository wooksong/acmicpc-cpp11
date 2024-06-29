#include <iostream>

int
main ()
{
  const std::string first_ten_digits = "9780921418";
  const std::string msg_prefix = "The 1-3-sum is ";
  const size_t len_isbn = 13;
  std::string isbn (first_ten_digits);
  char digit;
  int sum;

  // freopen("input.txt", "r", stdin);
  while (std::cin >> digit) {
    isbn += digit;
  }

  sum = 0;
  for (size_t i = 0; i < len_isbn; ++i) {
    int d = static_cast<int> (isbn[i] - '0');

    sum += (i % 2 == 1 ? d * 3 : d * 1);
  }

  std::cout << msg_prefix << sum << "\n";
  return 0;
}
