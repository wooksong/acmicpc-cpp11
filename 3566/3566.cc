#include <iostream>
#include <memory.h>
#include <vector>

typedef struct {
  uint32_t rh;
  uint32_t rv;
  uint32_t sh;
  uint32_t sv;
  uint32_t p;
} monitor_t;

int
main ()
{
  uint32_t n, rh, rv, sh, sv;
  std::vector<monitor_t> monitors;

  // freopen("input.txt", "r", stdin);
  std::cin >> rh >> rv >> sh >> sv;
  std::cin >> n;
  monitors = std::vector<monitor_t> (n);

  for (uint32_t i = 0; i < n; ++i) {
    std::cin >> monitors[i].rh >> monitors[i].rv >> monitors[i].sh
        >> monitors[i].sv >> monitors[i].p;
  }

  uint32_t min_p = UINT32_MAX;
  for (uint32_t i = 0; i < n; ++i) {
    monitor_t m = monitors[i];
    uint32_t h_cnts, v_cnts, price;

    h_cnts = std::max (rh % m.rh == 0 ? rh / m.rh : rh / m.rh + 1,
        sh % m.sh == 0 ? sh / m.sh : sh / m.sh + 1);
    v_cnts = std::max (rv % m.rv == 0 ? rv / m.rv : rv / m.rv + 1,
        sv % m.sv == 0 ? sv / m.sv : sv / m.sv + 1);
    price = h_cnts * v_cnts * m.p;
    if (price < min_p)
      min_p = price;

    h_cnts = std::max (rh % m.rv == 0 ? rh / m.rv : rh / m.rv + 1,
        sh % m.sv == 0 ? sh / m.sv : sh / m.sv + 1);
    v_cnts = std::max (rv % m.rh == 0 ? rv / m.rh : rv / m.rh + 1,
        sv % m.sh == 0 ? sv / m.sh : sv / m.sh + 1);
    price = h_cnts * v_cnts * m.p;
    if (price < min_p)
      min_p = price;
  }

  std::cout << min_p << "\n";

  return 0;
}
