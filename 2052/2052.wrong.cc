#include <iostream>

int
main ()
{
  uint32_t N;
  uint32_t cnt = 0;
  double ans = 1;
  std::string res;
  std::string str_ans;

  std::cin >> N;
  for (uint32_t i = 0; i < N; ++i) {
    ans /= 2;
    if (1 > ans) {
      ans *= 10;
      cnt++;
    }
  }

  res = "0.";
  for (uint32_t i = 0; i < cnt - 1; ++i) {
    res.append ("0");
  }

  str_ans = std::to_string (ans);
  for (auto iter = str_ans.begin (); iter != str_ans.end (); ++iter) {
    if (*iter == '.')
      continue;
    res.push_back (*iter);
  }
  for (auto iter = res.rbegin (); iter != res.rend (); ++iter) {
    if (*iter == '0') {
      *iter = '\0';
    } else {
      break;
    }
  }
  std::cout << res << "\n";

  return 0;
}
