#include <algorithm>
#include <iostream>
#include <vector>

int
main ()
{
  std::vector<int> balance_weights;
  int target_weight;
  int N;

  freopen ("input.txt", "r", stdin);

  std::cin >> N;
  balance_weights = std::vector<int> (N);
  for (int i = 0; i < N; ++i) {
    std::cin >> balance_weights[i];
  }

  std::sort (balance_weights.begin (), balance_weights.end ());
  target_weight = 1;
  for (int i = 0; i < N; ++i) {
    if (balance_weights[i] > target_weight)
      break;
    target_weight += balance_weights[i];
  }

  std::cout << target_weight << "\n";

  return 0;
}
