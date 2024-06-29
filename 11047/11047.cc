#include <iostream>
#include <vector>

int
main ()
{
  int val = 0;
  int cnt = 0;
  std::vector<int> coin_values;
  int N, K;

  // freopen("input.txt", "r", stdin);
  std::cin >> N >> K;
  coin_values = std::vector<int> (N);

  for (int i = 0; i < N; ++i) {
    std::cin >> coin_values[i];
  }

  for (auto iter = coin_values.rbegin (); iter != coin_values.rend (); ++iter) {
    int remains = K - val;
    int num_coins;

    if (remains < *iter)
      continue;
    num_coins = remains / *iter;

    val += (num_coins * (*iter));
    cnt += num_coins;
  }

  std::cout << cnt << "\n";
  return 0;
}
