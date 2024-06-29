#include <iostream>
#include <vector>

constexpr size_t MAX_PRIME_NUM = 1000001;
std::vector<size_t> sieve (MAX_PRIME_NUM, 1);
std::vector<size_t> prime_numbers;

int
main ()
{
  size_t N;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> N;

  sieve[0] = 0;
  sieve[1] = 0;

  for (size_t i = 2; i < MAX_PRIME_NUM; ++i) {
    for (size_t j = 2; i * j < MAX_PRIME_NUM; ++j) {
      if (sieve[i * j] == 0) {
        continue;
      }

      sieve[i * j] = 0;
    }
  }

  prime_numbers.reserve (MAX_PRIME_NUM);
  for (size_t i = 2; i < MAX_PRIME_NUM; ++i) {
    if (sieve[i] == 1) {
      prime_numbers.push_back (i);
    }
  }

  for (size_t i = 0; i < N; ++i) {
    std::string ans;
    size_t key;

    std::cin >> key;

    ans = "YES\n";
    for (size_t p : prime_numbers) {
      if (key % p == 0) {
        ans = "NO\n";
        break;
      }
    }

    std::cout << ans;
  }
  return 0;
}
