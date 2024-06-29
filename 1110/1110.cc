#include <iostream>

uint32_t sum_each_digit (uint32_t num);

int
main ()
{
  uint32_t N, cnt, new_N;

  std::cin >> N;

  cnt = 0;
  new_N = N;
  while (true) {
    new_N = new_N % 10 * 10 + sum_each_digit (new_N) % 10;
    cnt++;
    if (new_N == N)
      break;
  }
  std::cout << cnt << "\n";
  return 0;
}

uint32_t
sum_each_digit (uint32_t n)
{
  uint32_t sum = 0;

  while (n != 0) {
    sum += n % 10;
    n /= 10;
  }

  return sum;
}
