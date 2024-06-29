#include <iostream>

int
main ()
{
  uint32_t X, N, a, b, sum;

  freopen ("input.txt", "r", stdin);

  std::cin >> X;
  std::cin >> N;

  sum = 0;
  for (uint32_t i = 0; i < N; ++i) {
    std::cin >> a >> b;
    sum += (a * b);
  }

  if (sum == X)
    std::cout << "Yes\n";
  else
    std::cout << "No\n";
  return 0;
}
