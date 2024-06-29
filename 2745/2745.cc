#include <iostream>

int
main ()
{
  std::string num;
  int64_t base;
  int64_t decimal;
  int64_t mul;

  // freopen("input.txt", "r", stdin);
  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> num >> base;

  decimal = 0;
  mul = 1;
  for (auto iter = num.rbegin (); iter != num.rend (); ++iter) {
    int64_t digit;

    if (*iter >= 'A' && *iter <= 'Z') {
      digit = static_cast<int64_t> (*iter - 'A' + 10);
    } else {
      digit = static_cast<int64_t> (*iter - '0');
    }

    decimal += (digit * mul);
    mul *= base;
  }

  std::cout << decimal << "\n";

  return 0;
}
