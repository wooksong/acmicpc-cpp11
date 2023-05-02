#include <iomanip>
#include <iostream>
#include <sstream>

int
main ()
{
  std::stringstream ss;
  std::string line;
  std::string unit;
  double val;
  int N;

  // freopen("input.txt", "r", stdin);

  std::cin >> N;
  std::cin.ignore ();
  for (int i = 0; i < N; ++i) {
    std::string cunit;
    double cval = 0.0L;

    std::getline (std::cin, line);

    ss.clear ();
    ss.str (line);
    ss >> val >> unit;

    if (unit == "kg") {
      cunit = "lb";
      cval = val * 2.2046;
    } else if (unit == "lb") {
      cunit = "kg";
      cval = val * 0.4536;
    } else if (unit == "l") {
      cunit = "g";
      cval = val * 0.2642;
    } else if (unit == "g") {
      cunit = "l";
      cval = val * 3.7854;
    }

    std::cout << std::fixed << std::setprecision (4) << cval;
    std::cout << " " + cunit << "\n";
  }

  return 0;
}
