#include <iostream>

int
main ()
{
  uint32_t T, H, W, N;
  uint32_t i;

  // freopen("input.txt", "r", stdin);
  std::cin >> T;
  for (i = 0; i < T; ++i) {
    uint32_t h = 0;
    uint32_t w = 0;
    std::cin >> H >> W >> N;
    h = N % H;
    w = N / H;
    if (h == 0) {
      h = H;
    } else {
      w += 1;
    }
    printf ("%u%02u\n", h, w);
  }

  return 0;
}
