#include <iostream>

int
main ()
{
  int k = 10;
  int N;

  // freopen("input.txt", "r", stdin);
  std::cin >> N;

  while (N > k) {
    int r = N % k;

    if ((r) >= (k / 2)) {
      N -= (r);
      N += k;
    } else {
      N -= (r);
    }
    k *= 10;
  }

  std::cout << N << "\n";

  return 0;
}
