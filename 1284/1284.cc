#include <iostream>

constexpr int MAX_LEN = 5;

int
main ()
{
  char buf[MAX_LEN];

  while (std::cin.getline (buf, MAX_LEN)) {
    std::string num = std::string (buf);
    uint32_t width;

    if (num == "0")
      break;

    width = 0;
    for (auto iter = num.rbegin (); iter != num.rend (); ++iter) {
      switch (*iter) {
        case '1':
          width += 2;
          break;
        case '0':
          width += 4;
          break;
        default:
          width += 3;
      }
    }
    width += 2;
    if (num.length () > 1) {
      width += (num.length () - 1);
    }
    printf ("%u\n", width);
  }

  return 0;
}
