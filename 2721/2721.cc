#include <iostream>

int func_w (int n);
int func_t (int n);

int
main ()
{
  int T;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cout.tie (nullptr);
  std::cin.tie (nullptr);

  std::cin >> T;

  while (T--) {
    int n;

    std::cin >> n;

    std::cout << func_w (n) << "\n";
  }

  return 0;
}

int
func_t (int n)
{
  int sum = 0;

  for (int i = 1; i <= n; ++i) {
    sum += i;
  }

  return sum;
}

int
func_w (int n)
{
  int sum = 0;

  for (int k = 1; k <= n; ++k) {
    sum += (k * func_t (k + 1));
  }

  return sum;
}
