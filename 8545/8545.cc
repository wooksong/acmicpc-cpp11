#include <iostream>

int
main ()
{
  std::string result = "";
  std::string input;

  // freopen("input.txt", "r", stdin);
  std::cin >> input;
  for (auto iter = input.rbegin (); iter != input.rend (); ++iter) {
    result += (*iter);
  }

  std::cout << result << "\n";
  return 0;
}
