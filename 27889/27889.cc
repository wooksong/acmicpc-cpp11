#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, std::string> dict = {
  { "NLCS", "North London Collegiate School" },
  { "BHA", "Branksome Hall Asia" },
  { "KIS", "Korea International School" },
  { "SJA", "St. Johnsbury Academy" },
};

int
main ()
{
  std::string abbrv;

  std::cin >> abbrv;
  std::cout << dict[abbrv] << "\n";

  return 0;
}
