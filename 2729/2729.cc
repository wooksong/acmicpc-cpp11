#include <bitset>
#include <iostream>

constexpr size_t MAX_BITLEN = 81;

int
main ()
{
  int num_tcs;

  // freopen("input.txt", "r", stdin);
  std::cin >> num_tcs;

  while (num_tcs--) {
    std::bitset<MAX_BITLEN> bits_lhs, bits_rhs;
    std::bitset<MAX_BITLEN> bits_ans;
    std::string lhs, rhs;
    std::string ans;
    bool carry;
    size_t found;

    std::cin >> lhs >> rhs;

    bits_lhs = std::bitset<MAX_BITLEN> (lhs);
    bits_rhs = std::bitset<MAX_BITLEN> (rhs);
    bits_ans.reset ();

    carry = false;

    for (size_t i = 0; i < MAX_BITLEN; ++i) {
      if (bits_lhs.test (i) && bits_rhs.test (i)) {
        carry ? bits_ans.set (i) : bits_ans.reset (i);
        carry = true;
      } else if (bits_lhs.test (i) || bits_rhs.test (i)) {
        carry ? bits_ans.reset (i) : bits_ans.set (i);
      } else {
        carry ? bits_ans.set (i) : bits_ans.reset (i);
        carry = false;
      }
    }

    ans = bits_ans.to_string ();
    found = ans.find_first_not_of ('0');
    if (found == std::string::npos) {
      std::cout << "0\n";
    } else {
      std::cout << ans.substr (found) << "\n";
    }
  }
  return 0;
}
