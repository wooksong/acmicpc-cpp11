#include <iostream>
#include <memory.h>

constexpr uint32_t CNT_NUMS = 8;

typedef enum {
  NONE = 0,
  MIXED = 1,
  DESCENDING = 2,
  ASCENDING = 3,
} play_pattern_t;

const char *PLAY_PATTERN_STRINGS[] = { "none", "mixed", "descending", "ascending" };

int
main ()
{
  uint32_t nums[CNT_NUMS];

  // freopen("input.txt", "r", stdin);
  memset (nums, 0, sizeof (nums[0]) * CNT_NUMS);
  for (uint32_t i = 0; i < CNT_NUMS; ++i) {
    std::cin >> nums[i];
  }

  uint32_t prev_val = nums[0];
  play_pattern_t cur_pattern = NONE;
  play_pattern_t tmp_pattern;
  for (uint32_t i = 1; i < CNT_NUMS; ++i) {
    if (nums[i] > prev_val) {
      tmp_pattern = ASCENDING;
    } else {
      tmp_pattern = DESCENDING;
    }
    if (cur_pattern == NONE || cur_pattern == tmp_pattern) {
      cur_pattern = tmp_pattern;
      prev_val = nums[i];
      continue;
    } else if (cur_pattern != tmp_pattern) {
      cur_pattern = MIXED;
      break;
    }
  }

  std::cout << PLAY_PATTERN_STRINGS[cur_pattern] << "\n";
}
