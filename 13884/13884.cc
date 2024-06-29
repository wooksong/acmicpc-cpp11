#include <algorithm>
#include <iostream>
#include <vector>

int
main ()
{
  std::vector<int> v;
  std::vector<int> v_sorted;
  int P;

  // freopen("input.txt", "r", stdin);

  std::cin >> P;
  for (int p = 0; p < P; ++p) {
    int K, N;

    v.clear ();
    v_sorted.clear ();
    std::cin >> K >> N;

    for (int n = 0; n < N; ++n) {
      int in;
      std::cin >> in;

      v.push_back (in);
      v_sorted.push_back (in);
    }

    std::sort (&v_sorted[0], &v_sorted[N]);
    int i = 0;
    for (auto iter = v.begin (); iter != v.end (); ++iter) {
      if (*iter == v_sorted[i])
        ++i;
    }

    std::cout << K << " " << N - i << "\n";
  }

  return 0;
}
