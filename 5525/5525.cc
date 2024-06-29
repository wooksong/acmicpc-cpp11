#include <iostream>

int
main ()
{
  int N, M, len, cnt;
  bool toggle;
  std::string S;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  // freopen("input.txt", "r", stdin);
  std::cin >> N;
  std::cin >> M;
  std::cin >> S;

  len = 0;
  toggle = true;
  cnt = 0;
  for (auto iter = S.begin (); iter != S.end (); ++iter) {
    if (*iter == 'I') {
      if (toggle) {
        len++;
        toggle = !toggle;
      } else {
        len = 1;
        toggle = false;
      }
    } else {
      if (!toggle) {
        len++;
      } else {
        len = 0;
      }
      toggle = true;
    }

    if (len == (2 * N + 1)) {
      cnt++;
      len -= 2;
      toggle = false;
    }
  }
  std::cout << cnt << "\n";

  return 0;
}
