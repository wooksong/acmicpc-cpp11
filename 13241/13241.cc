#include <iostream>

using bigint_t = long long int;

bigint_t gcd (bigint_t l, bigint_t r);
bigint_t lcm (bigint_t l, bigint_t r, bigint_t gcd);

int
main ()
{
  bigint_t A, B;

  // freopen("input.txt", "r", stdin);
  std::cin >> A >> B;

  if (B > A) {
    std::swap (A, B);
  }

  std::cout << lcm (A, B, gcd (A, B)) << "\n";

  return 0;
}

bigint_t
gcd (bigint_t l, bigint_t r)
{
  if (l % r == 0) {
    return r;
  }

  return gcd (r, l % r);
}

bigint_t
lcm (bigint_t l, bigint_t r, bigint_t gcd)
{
  return (l / gcd) * r;
}
