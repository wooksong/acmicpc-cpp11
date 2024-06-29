#include <iostream>
#include <vector>

constexpr int MAX_LEN_BIG_UINT = 781;
constexpr int NUM_DIGITS = 10;

std::string mul_str_bigint (std::string &lhs, std::string &rhs);
std::string decrease_str_bigint (std::string &lhs);

std::string cal_factorial (std::string &n);

int
main ()
{
  std::vector<int> cnt (NUM_DIGITS);
  // freopen("input.txt", "r", stdin);

  while (true) {
    std::string fact;
    std::string N;

    std::cin >> N;
    if (N == "0")
      break;
    std::fill_n (cnt.begin (), NUM_DIGITS, 0);
    fact = cal_factorial (N);
    for (char digit : fact) {
      int idx = static_cast<int> (digit - '0');

      cnt[idx]++;
    }
    std::cout << N << "! --\n";
    for (int i = 0; i < NUM_DIGITS; ++i) {
      printf ("   (%d)%5d ", i, cnt[i]);
      if (i == 4)
        std::cout << "\n";
    }
    std::cout << "\n";
  }
  return 0;
}

std::string
cal_factorial (std::string &n)
{
  if (n == "1")
    return std::string ("1");
  std::string n_decreased = decrease_str_bigint (n);
  std::string fact_n_decareased = cal_factorial (n_decreased);

  return mul_str_bigint (fact_n_decareased, n);
}

std::string
decrease_str_bigint (std::string &lhs)
{
  std::vector<int> tmp (lhs.length (), 0);
  std::string ret;
  int pos = 1;
  int carry;

  tmp[0] = static_cast<int> (lhs.back () - '0') - 1;
  for (auto l = lhs.rbegin () + 1; l != lhs.rend (); ++l) {
    tmp[pos++] = static_cast<int> (*l - '0');
  }

  carry = 0;
  for (auto i = tmp.begin (); i != tmp.end (); ++i) {
    *i = *i + carry;

    carry = 0;
    if (*i < 0) {
      *i += 10;
      carry = -1;
    }
  }

  bool is_leading_zero = true;

  for (auto i = tmp.rbegin (); i != tmp.rend (); ++i) {
    if (is_leading_zero && *i == 0)
      continue;
    is_leading_zero = false;
    ret.push_back (static_cast<char> (*i + '0'));
  }

  return ret;
}

std::string
mul_str_bigint (std::string &lhs, std::string &rhs)
{
  std::vector<int> tmp (MAX_LEN_BIG_UINT);
  std::string ret;
  int pos = -1;
  int carry;

  if (rhs.length () > lhs.length ())
    std::swap (lhs, rhs);

  for (auto r = rhs.rbegin (); r != rhs.rend (); ++r) {
    int i = 0;

    pos += 1;
    for (auto l = lhs.rbegin (); l != lhs.rend (); ++l, ++i) {
      int il = static_cast<int> (*l - '0');
      int ir = static_cast<int> (*r - '0');
      tmp[pos + i] += (il * ir);
    }
  }

  carry = 0;
  for (auto i = tmp.begin (); i != tmp.end (); ++i) {
    *i = *i + carry;

    carry = *i / 10;
    *i %= 10;
  }

  bool is_leading_zero = true;
  for (auto i = tmp.rbegin (); i != tmp.rend (); ++i) {
    if (is_leading_zero && *i == 0)
      continue;
    is_leading_zero = false;
    ret.push_back (static_cast<char> (*i + '0'));
  }

  return ret;
}
