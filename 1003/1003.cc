#include <iostream>

constexpr int MAX_NUM = 41;

struct Count {
  int num_one;
  int num_zero;
};

int
main ()
{
  int N, T;
  Count num_printed[MAX_NUM];
  num_printed[0].num_one = 0;
  num_printed[0].num_zero = 1;
  num_printed[1].num_one = 1;
  num_printed[1].num_zero = 0;

  // freopen("input.txt", "r", stdin);
  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    std::cin >> N;
    for (int f = 2; f <= N; ++f) {
      num_printed[f].num_one = num_printed[f - 1].num_one + num_printed[f - 2].num_one;
      num_printed[f].num_zero = num_printed[f - 1].num_zero + num_printed[f - 2].num_zero;
    }

    std::cout << num_printed[N].num_zero << " " << num_printed[N].num_one << "\n";
  }

  return 0;
}
