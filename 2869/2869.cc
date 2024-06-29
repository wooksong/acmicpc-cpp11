#include <iostream>

int
main ()
{
  uint32_t A, B, V, day_and_night, remainder, days;

  // freopen("input.txt", "r", stdin);
  std::cin >> A >> B >> V;

  day_and_night = A - B;
  remainder = (V - A) % day_and_night;
  days = (V - A) / day_and_night;

  if (remainder != 0) {
    remainder += A;
    while (remainder >= A) {
      remainder -= day_and_night;
      days++;
    }
  }
  std::cout << days + 1 << "\n";
  return 0;
}
