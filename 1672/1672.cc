#include <iostream>
#include <unordered_map>

int
main ()
{
  std::unordered_map<std::string, char> dict = {
    { "AA", 'A' },
    { "AG", 'C' },
    { "AC", 'A' },
    { "AT", 'G' },
    { "GA", 'C' },
    { "GG", 'G' },
    { "GC", 'T' },
    { "GT", 'A' },
    { "CA", 'A' },
    { "CG", 'T' },
    { "CC", 'C' },
    { "CT", 'G' },
    { "TA", 'G' },
    { "TG", 'A' },
    { "TC", 'G' },
    { "TT", 'T' },
  };
  std::string seq;
  int N;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> N;
  std::cin >> seq;

  while (seq.length () > 1) {
    std::string enc = seq.substr (seq.length () - 2, 2);

    seq.pop_back ();
    seq.pop_back ();
    seq.push_back (dict[enc]);
  }

  std::cout << seq << "\n";

  return 0;
}
