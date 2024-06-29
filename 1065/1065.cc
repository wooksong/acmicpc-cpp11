#include <iostream>

int
main ()
{
  int N, cnt;

  std::cin >> N;
  if (N < 100) {
    cnt = N;
    goto out;
  }
  cnt = 99;
  for (int i = 100; i <= N; ++i) {
    std::string str_num = std::to_string (i);
    int prev = static_cast<int> (str_num[1] - '0');
    int diff = static_cast<int> (str_num[0] - '0') - prev;
    size_t len = str_num.length ();
    bool found = true;

    for (size_t i = 2; i < len; ++i) {
      int next = static_cast<int> (str_num[i] - '0');

      if (diff != (prev - next)) {
        found = false;
        break;
      }
      prev = next;
    }

    if (found) {
      cnt++;
    }
  }
out:
  std::cout << cnt << "\n";
  return 0;
}
