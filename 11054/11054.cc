#include <iostream>
#include <vector>

int
main ()
{
  int ans = INT32_MIN;
  std::vector<int> seq;
  std::vector<int> lis;
  std::vector<int> lds;
  int len_seq;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> len_seq;

  seq = std::vector<int> (len_seq);
  for (int i = 0; i < len_seq; ++i) {
    std::cin >> seq[i];
  }

  lis = std::vector<int> (len_seq, 1);
  for (int i = 0; i < len_seq; ++i) {
    for (int j = 0; j < i; ++j) {
      if (seq[i] > seq[j]) {
        lis[i] = std::max (lis[i], lis[j] + 1);
      }
    }
  }

  seq = std::vector<int> (seq.rbegin (), seq.rend ());
  lds = std::vector<int> (len_seq, 1);
  for (int i = 0; i < len_seq; ++i) {
    for (int j = 0; j < i; ++j) {
      if (seq[i] > seq[j]) {
        lds[i] = std::max (lds[i], lds[j] + 1);
      }
    }
  }

  lds = std::vector<int> (lds.rbegin (), lds.rend ());
  for (int i = 0; i < len_seq; ++i) {
    ans = std::max (ans, lis[i] + lds[i] - 1);
  }

  std::cout << ans << "\n";

  return 0;
}
