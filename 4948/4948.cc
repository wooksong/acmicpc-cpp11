#include <iostream>
#include <vector>

constexpr size_t MAX_N = 123456;
std::vector<int> prime_numbers;

int
main ()
{
  size_t n;
  size_t doubled_N = MAX_N * 2 + 2;

  // freopen("input.txt", "r", stdin);

  prime_numbers = std::vector<int> (doubled_N, 1);
  prime_numbers[0] = 0;
  prime_numbers[1] = 0;

  for (size_t i = 2; i < doubled_N; ++i) {
    for (size_t j = 2; i * j < doubled_N; j++) {
      size_t idx = i * j;
      if (prime_numbers[idx] == 1) {
        prime_numbers[idx] = 0;
      }
    }
  }

  while (std::cin >> n) {
    size_t doubled_n = 2 * n;
    size_t cnt = 0;
    if (n == 0) {
      break;
    }

    for (size_t i = n + 1; i <= doubled_n; ++i) {
      if (prime_numbers[i]) {
        cnt++;
      }
    }

    std::cout << cnt << "\n";
  }
  return 0;
}
