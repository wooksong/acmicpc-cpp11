#include <iostream>
#include <vector>

int
main ()
{
  std::vector<bool> cupholders;
  std::string seats;
  int tmp;
  int ans;
  int N;

  // freopen("input.txt", "r", stdin);

  std::cin >> N;
  cupholders = std::vector<bool> (N + 1, true);
  std::cin >> seats;

  cupholders[0] = 1;
  cupholders[N] = 1;
  tmp = 0;
  for (int i = 0; i < N; ++i) {
    if (seats[i] == 'L') {
      if (tmp == 1)
        cupholders[i] = false;
      else if (tmp == 2) {
        tmp = 0;
      }
      ++tmp;
    }
  }

  tmp = 0;
  for (int i = 0; i < N + 1; ++i) {
    if (cupholders[i])
      ++tmp;
  }

  if (tmp == (N + 1))
    ans = N;
  else
    ans = tmp;

  std::cout << ans << "\n";

  return 0;
}
