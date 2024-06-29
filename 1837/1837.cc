#include <iostream>
#include <vector>

void sieve (uint32_t n, std::vector<uint32_t> &prime_numbers);
uint32_t bigmod (std::string str_num, uint32_t q);

int
main ()
{
  std::string P;
  std::vector<uint32_t> prime_numbers;
  uint32_t K;

  std::cin >> P >> K;
  sieve (K, prime_numbers);

  for (uint32_t q : prime_numbers) {
    uint32_t r = bigmod (P, q);
    if (r == 0 && q < K) {
      printf ("BAD %u\n", q);
      return 0;
    }
  }

  printf ("GOOD\n");
  return 0;
}

void
sieve (uint32_t n, std::vector<uint32_t> &prime_numbers)
{
  std::vector<bool> primes = std::vector<bool> (n + 1, true);

  for (uint32_t i = 0; i < n + 1; ++i) {
    if (i == 0 || i == 1) {
      primes[i] = false;
      continue;
    }
    if (primes[i] == true) {
      uint32_t j = 2;

      prime_numbers.push_back (i);

      while ((i * j) < (n + 1)) {
        primes[i * j] = false;
        ++j;
      }
    }
  }
}

uint32_t
bigmod (std::string str_num, uint32_t q)
{
  uint32_t ans = 0;

  for (auto iter = str_num.begin (); iter != str_num.end (); ++iter) {
    ans = (ans * 10 + (uint32_t) *iter - '0') % q;
  }

  return ans;
}
