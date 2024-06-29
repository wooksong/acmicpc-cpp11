#include <iostream>
#include <set>

int
main ()
{
  std::multiset<uint64_t> warriors_sb;
  std::multiset<uint64_t> warriors_sj;
  int T;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> T;
  while (T--) {
    int N, M;

    std::cin >> N >> M;

    warriors_sj.clear ();
    warriors_sb.clear ();

    for (int i = 0; i < N; ++i) {
      uint64_t p;

      std::cin >> p;
      warriors_sj.insert (p);
    }

    for (int j = 0; j < M; ++j) {
      uint64_t p;

      std::cin >> p;
      warriors_sb.insert (p);
    }

    {
      auto iter_sj = warriors_sj.begin ();
      auto iter_sb = warriors_sb.begin ();

      while (iter_sj != warriors_sj.end () && iter_sb != warriors_sb.end ()) {
        uint64_t p_sj = *iter_sj;
        uint64_t p_sb = *iter_sb;

        if (p_sj < p_sb) {
          iter_sj = warriors_sj.upper_bound (p_sb);
        } else if (p_sj > p_sb) {
          iter_sb = warriors_sb.upper_bound (p_sj);
        } else {
          iter_sb = warriors_sb.upper_bound (p_sb);
        }
      }

      if (iter_sj != warriors_sj.end () && iter_sb != warriors_sb.end ()) {
        std::cout << "C\n";
      } else if (iter_sj != warriors_sj.end ()) {
        std::cout << "S\n";
      } else {
        std::cout << "B\n";
      }
    }
  }
  return 0;
}
