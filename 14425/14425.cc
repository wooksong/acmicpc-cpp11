#include <iostream>
#include <unordered_set>

const size_t MAX_LEN = 500;
int
main ()
{
  std::unordered_set<std::string> set_s;
  size_t N, M;
  size_t ans = 0;
  char buf[MAX_LEN];

  // freopen ("input.txt", "r", stdin);

  std::cin >> N >> M;

  for (size_t i = 0; i < N; ++i) {
    scanf ("%s", buf);

    set_s.insert (buf);
    buf[0] = '\0';
  }

  for (size_t i = 0; i < M; ++i) {
    scanf ("%s", buf);


    if (set_s.find (buf) != set_s.end ())
      ++ans;
    buf[0] = '\0';
  }

  std::cout << ans << "\n";

  return 0;
}
