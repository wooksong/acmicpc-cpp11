#include <iostream>

int to_num (std::string s);
int
main ()
{
  std::string L, R;
  int cnt = 0;

  // freopen("input.txt", "r", stdin);

  std::cin >> L >> R;
  if (L.length () == R.length ()) {
    for (size_t i = 0; i < L.length (); ++i) {
      if ((L[i] == R[i]) && (L[i] == '8')) {
        cnt++;
      } else if (L[i] != R[i]) {
        break;
      }
    }
  }

  std::cout << cnt << "\n";

  return 0;
}
