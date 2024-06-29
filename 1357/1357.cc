#include <iostream>

int to_int (std::string &num);
std::string rev (std::string &num);
std::string add_str (std::string &lhs, std::string &rhs);

int
main ()
{
  std::string lhs, rhs;
  std::string ans;

  // freopen("input.txt", "r", stdin);

  std::cin >> lhs >> rhs;

  lhs = rev (lhs);
  rhs = rev (rhs);
  ans = add_str (lhs, rhs);

  std::cout << rev (ans) << "\n";

  return 0;
}

int
to_int (std::string &num)
{
  int i = 1;
  int ret = 0;

  for (auto iter = num.rbegin (); iter != num.rend (); ++iter) {
    ret += (static_cast<int> (*iter - '0') * i);
    i *= 10;
  }

  return ret;
}

std::string
rev (std::string &num)
{
  std::string ret;
  size_t pos;

  for (auto iter = num.rbegin (); iter != num.rend (); ++iter) {
    ret.push_back (*iter);
  }

  pos = 0;
  while (ret[pos] == '0') {
    pos++;
  }

  return ret.substr (pos);
}

std::string
add_str (std::string &lhs, std::string &rhs)
{
  int l, r;

  l = to_int (lhs);
  r = to_int (rhs);

  return std::to_string (l + r);
}
