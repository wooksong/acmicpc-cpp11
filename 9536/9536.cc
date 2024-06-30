#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>

int
main ()
{
  const size_t MAX_LEN_WORD = 100;
  const size_t MAX_N_WORDS = 100;
  std::unordered_set<std::string> words;
  std::vector<std::string> v;
  std::stringstream ss;
  size_t n;
  std::string s;
  std::string animal;
  std::string goes;
  std::string word;


  s.reserve (MAX_LEN_WORD * MAX_N_WORDS);
  v.reserve (MAX_N_WORDS);
  animal.reserve (MAX_LEN_WORD);
  goes.reserve (MAX_LEN_WORD);
  word.reserve (MAX_LEN_WORD);
  // freopen ("input.txt", "r", stdin);

  std::cin >> n;
  for (size_t i = 0; i < n; ++i) {
    std::cin.ignore ();

    std::getline (std::cin, s);

    ss = std::stringstream (s);
    {
      while (std::getline (ss, word, ' ')) {
        words.insert (word);
        v.emplace_back (word);
        word[0] = '\0';
      }
    }
    {

      while (true) {
        animal[0] = '\0';
        goes[0] = '\0';
        word[0] = '\0';

        std::cin >> animal >> goes >> word;

        if (animal == "what") {
          std::cin >> goes >> word;
          break;
        }


        words.erase (word);
      }
    }

    for (auto it : v) {
      if (words.find (it) == words.end ())
        continue;
      std::cout << it << " ";
    }
    std::cout << "\n";
    s[0] = '\0';
    v.clear ();
    words.clear ();
  }


  return 0;
}
