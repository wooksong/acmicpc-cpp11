#include <bitset>
#include <iostream>
#include <vector>

constexpr int MAX_NUM_STATEMENTS = 51;

int
main ()
{
  std::vector<int> statements (MAX_NUM_STATEMENTS, 0);
  int max_num_trues = 0;
  int ans = MAX_NUM_STATEMENTS;
  int N;

  freopen ("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int num_trues;

    std::cin >> num_trues;
    statements[num_trues]++;
    if (num_trues > max_num_trues) {
      max_num_trues = num_trues;
    }
  }

  for (int i = max_num_trues; i >= 1; --i) {
    if (i == statements[i]) {
      ans = i;
      break;
    }
  }

  if (ans == MAX_NUM_STATEMENTS) {
    if (statements[0] > 0) {
      ans = -1;
    } else {
      ans = 0;
    }
  }

  std::cout << ans << "\n";

  return 0;
}
