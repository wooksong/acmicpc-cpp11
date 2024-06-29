#include <iostream>
#include <vector>

constexpr int MAX_NUM_LECTURES = 100001;
constexpr int MAX_LEN_LECTURE = 10001;
constexpr int UPPER_BOUND = MAX_NUM_LECTURES * MAX_LEN_LECTURE;
constexpr int LOWER_BOUND = 1;

bool check_pack (std::vector<int> &arr, int len, int num);

int
main ()
{
  int num_lectures, num_mediums;
  int ans = INT32_MAX;
  std::vector<int> lectures;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);
  std::cin >> num_lectures >> num_mediums;

  lectures = std::vector<int> (num_lectures);
  for (int i = 0; i < num_lectures; ++i) {
    std::cin >> lectures[i];
  }

  {
    int l, m, u;

    l = LOWER_BOUND;
    u = UPPER_BOUND;

    while (l < u) {
      m = (l + u) / 2;
      if (check_pack (lectures, m, num_mediums)) {
        ans = std::min (ans, m);
        u = m;
      } else {
        l = m + 1;
      }
    }
  }

  std::cout << ans << "\n";

  return 0;
}

bool
check_pack (std::vector<int> &arr, int len, int num)
{
  int len_each = 0;
  int cnt_mediums = 1;

  for (int each : arr) {
    if (each > len) {
      cnt_mediums = INT32_MAX;
      break;
    }
    if ((len_each + each) > len) {
      len_each = 0;
      cnt_mediums += 1;
    }
    len_each += each;
  }

  return ((cnt_mediums > num) ? false : true);
}
