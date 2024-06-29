#include <iostream>

void eliminate_leading_zero (std::string &num);
void add_one_to (std::string &addend);
void subtract (std::string &minuend, std::string substrahend);
bool greater_than (std::string l, std::string r);

int
main ()
{
  std::string A, B;
  std::string big, small, diff;

  std::ios_base::sync_with_stdio (false);
  std::cout.tie (0);
  std::cin.tie (0);
  // freopen("input.txt", "r", stdin);
  std::cin >> A >> B;
  if (A == B) {
    std::cout << "0\n";
    return 0;
  }
  if (greater_than (A, B)) {
    big = std::string (A);
    diff = std::string (A);
    small = std::string (B);
  } else {
    big = std::string (B);
    diff = std::string (B);
    small = std::string (A);
  }
  add_one_to (small);
  subtract (diff, small);
  if (diff.empty ()) {
    std::cout << "0\n";
  } else {
    std::cout << diff << "\n";
    std::cout << small << " ";
    while (small != big) {
      add_one_to (small);
      if (small == big)
        break;
      std::cout << small << " ";
    }
    std::cout << "\n";
  }
  return 0;
}

void
eliminate_leading_zero (std::string &num)
{
  while (num.length ()) {
    if (num.at (0) == '0') {
      num.erase (0, 1);
    } else {
      break;
    }
  }
}
void
add_one_to (std::string &addend)
{
  uint32_t carry = 1;

  for (auto iter = addend.rbegin (); iter != addend.rend (); ++iter) {
    uint32_t digit = static_cast<uint32_t> (*iter - '0');

    digit = digit + carry;
    if (digit >= 10) {
      carry = 1;
      digit %= 10;
    } else {
      carry = 0;
    }

    *iter = static_cast<char> (digit + '0');
    if (carry == 0)
      break;
  }

  if (carry) {
    addend.insert (0, 1, '1');
  }
}

void
subtract (std::string &minuend, std::string substrahend)
{
  int32_t carry = 0;
  size_t ridx = minuend.length () - 1;

  for (auto iter = substrahend.rbegin (); iter != substrahend.rend (); ++iter) {
    int32_t min = static_cast<int32_t> (minuend.at (ridx) - '0');
    int32_t sub = static_cast<int32_t> (*iter - '0');

    sub += carry;
    carry = 0;
    if (min < sub) {
      min += 10;
      carry = 1;
    }
    min -= sub;

    minuend[ridx] = static_cast<char> (min + '0');
    if (ridx != 0)
      ridx--;
  }

  while (carry) {
    int32_t num = static_cast<int32_t> (minuend[ridx] - '0');

    if (num < 1) {
      num += 10;
      carry = 1;
    } else {
      carry = 0;
    }
    num -= 1;
    minuend[ridx--] = static_cast<char> (num + '0');
  }
  eliminate_leading_zero (minuend);
}

bool
greater_than (std::string l, std::string r)
{
  size_t l_len = l.length ();
  size_t r_len = r.length ();
  bool ret;

  if (l_len > r_len) {
    ret = true;
    goto ret_res;
  } else if (r_len > l_len) {
    ret = false;
    goto ret_res;
  }

  for (size_t idx = 0; idx < l_len; ++idx) {
    int32_t l_num = static_cast<int32_t> (l[idx] - '0');
    int32_t r_num = static_cast<int32_t> (r[idx] - '0');
    if (l_num == r_num)
      continue;

    if (l_num > r_num) {
      ret = true;
      goto ret_res;
    } else {
      ret = false;
      goto ret_res;
    }
  }

ret_res:
  return ret;
}
