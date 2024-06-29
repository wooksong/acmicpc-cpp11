#include <iostream>
#include <vector>

int64_t calc_gcd (int64_t l, int64_t r);
int64_t calc_lcm (int64_t l, int64_t r);

int
main ()
{
  int64_t N, denominator, sum, reduction;
  std::vector<int64_t> v;

  // freopen("input.txt", "r", stdin);
  std::cin >> N;

  for (int64_t i = 0; i < N; ++i) {
    int64_t tmp;

    std::cin >> tmp;
    v.push_back (tmp);
  }

  denominator = v[0];
  for (int64_t i = 1; i < N; ++i) {
    denominator = calc_lcm (denominator, v[i]);
  }

  sum = 0;
  for (int64_t i = 0; i < N; ++i) {
    sum += (denominator / v[i]);
  }

  reduction = calc_gcd (denominator, sum);
  denominator /= reduction;
  sum /= reduction;

  std::cout << denominator << "/" << sum << "\n";

  return 0;
}

int64_t
calc_gcd (int64_t l, int64_t r)
{
  if (l < r)
    std::swap (l, r);
  if (l % r == 0)
    return r;

  return calc_gcd (r, l % r);
}

int64_t
calc_lcm (int64_t l, int64_t r)
{
  return l / calc_gcd (l, r) * r;
}
