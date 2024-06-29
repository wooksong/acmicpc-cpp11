#include <iostream>
#include <vector>

std::string
print_answer (std::vector<int64_t> p, std::vector<int64_t> n)
{
  if (p.empty () && n.empty ()) {
    return "0";
  } else if (p.empty ()) {
    return "-";
  }
  return "+";
}

int
main ()
{
  uint32_t T = 3;
  uint32_t N;

  std::vector<int64_t> plus_nums;
  std::vector<int64_t> minus_nums;

  // freopen("input.txt", "r", stdin);

  for (uint32_t i = 0; i < T; ++i) {
    std::cin >> N;
    plus_nums.clear ();
    minus_nums.clear ();

    for (uint32_t j = 0; j < N; ++j) {
      int64_t num;

      std::cin >> num;

      if (num > 0) {
        plus_nums.push_back (num);
      } else if (num < 0) {
        minus_nums.push_back (num);
      }
    }

    while ((!plus_nums.empty ()) && (!minus_nums.empty ())) {
      int64_t sum = plus_nums.back () + minus_nums.back ();

      plus_nums.pop_back ();
      minus_nums.pop_back ();

      if (sum > 0) {
        plus_nums.push_back (sum);
      } else if (sum < 0) {
        minus_nums.push_back (sum);
      }
    }

    printf ("%s\n", print_answer (plus_nums, minus_nums).c_str ());
  }

  return 0;
}
