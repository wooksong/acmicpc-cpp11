#include <iostream>
#include <vector>

void toggle_boys (std::vector<bool> &v, int val);
void toggle_girls (std::vector<bool> &v, int val);

int
main ()
{
  int num_swchs, num_stdnts;
  uint32_t cnt;
  std::vector<bool> swchs;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  // freopen("input.txt", "r", stdin);
  std::cin >> num_swchs;

  swchs = std::vector<bool> (num_swchs, 0);
  for (int i = 0; i < num_swchs; ++i) {
    int n;
    std::cin >> n;
    swchs[i] = (n == 1);
  }

  std::cin >> num_stdnts;
  for (int i = 0; i < num_stdnts; ++i) {
    int gender, val;

    std::cin >> gender >> val;
    if (gender == 1) {
      toggle_boys (swchs, val);
    } else {
      toggle_girls (swchs, val);
    }
  }

  cnt = 0;
  for (int i = 0; i < num_swchs; ++i) {
    std::cout << (swchs[i] ? "1 " : "0 ");
    if (cnt++ == 19) {
      std::cout << "\n";
      cnt = 0;
    }
  }

  if (cnt != 0)
    std::cout << "\n";

  return 0;
}

void
toggle_boys (std::vector<bool> &v, int val)
{
  int v_size = v.size ();
  for (int i = val - 1; i < v_size; i += val) {
    v[i] = !v[i];
  }
}
void
toggle_girls (std::vector<bool> &v, int val)
{
  int s, e, v_size;

  val -= 1;
  s = val - 1;
  e = val + 1;
  v_size = v.size ();

  while (s >= 0 && e < v_size) {
    if (v[s] != v[e])
      break;
    --s;
    ++e;
  }

  for (int i = s + 1; i <= e - 1; ++i) {
    v[i] = !v[i];
  }
}
