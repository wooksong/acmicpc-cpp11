#include <iostream>
#include <vector>

void sieve (std::vector<int> &prime_numbers, int n);

int
main ()
{
  std::vector<int> arr_prime_numbers;
  std::vector<int> arr;
  size_t cnt = 0;
  int num_prime_ns;
  int i, j, N, sum;

  // freopen("input.txt", "r", stdin);
  std::cin >> N;

  arr = std::vector<int> (N + 1, 1);

  arr[0] = 0;
  arr[1] = 0;
  sieve (arr, N + 1);

  for (i = 0; i <= N; ++i) {
    if (arr[i] == 1) {
      arr_prime_numbers.push_back (i);
    }
  }
  num_prime_ns = arr_prime_numbers.size ();

  j = 0;
  sum = 0;
  cnt = 0;
  for (i = 0; i < num_prime_ns; ++i) {
    while (j < num_prime_ns && sum < N) {
      sum += arr_prime_numbers[j];
      ++j;
    }

    if (sum == N) {
      ++cnt;
    }
    sum -= arr_prime_numbers[i];
  }

  std::cout << cnt << "\n";
  return 0;
}

void
sieve (std::vector<int> &prime_numbers, int n)
{
  for (int i = 2; i < n; ++i) {
    for (int j = 2; j * i < n; ++j) {
      int idx = i * j;

      prime_numbers[idx] = 0;
    }
  }
}
