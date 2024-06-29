#include <iostream>

int
main ()
{
  std::string num;
  size_t pos;
  size_t len;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> num;
  pos = 1;
  len = num.length ();
  if (len <= 1) {
    goto prnout_no;
  }

  for (size_t i = pos; i < len; ++i) {
    std::string front = num.substr (0, i);
    std::string back = num.substr (i, len);
    size_t mul_f, mul_b;

    mul_f = 1;
    mul_b = 1;

    for (char c : front) {
      mul_f *= static_cast<size_t> (c - '0');
    }

    for (char c : back) {
      mul_b *= static_cast<size_t> (c - '0');
    }

    if (mul_f == mul_b) {
      std::cout << "YES\n";

      return 0;
    }
  }

prnout_no:
  std::cout << "NO\n";
  return 0;
}
