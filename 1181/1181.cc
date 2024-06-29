#include <iostream>
#include <vector>

constexpr size_t MAX_LEN = 51;
typedef enum {
  BEFORE = 0,
  AFTER = 1,
  SAME = 2,
} cmp_t;

cmp_t string_cmp (std::string &at, std::string &in);

int
main ()
{
  std::vector<std::vector<std::string>> words_by_len
      = std::vector<std::vector<std::string>> (MAX_LEN);
  uint32_t N;

  // freopen("input.txt", "r", stdin);

  std::cin >> N;
  for (uint32_t i = 0; i < N; ++i) {
    std::string word;
    std::vector<std::string> *words;
    size_t idx;

    std::cin >> word;
    idx = word.size ();
    words = &words_by_len[idx];

    if (words->empty ()) {
      words->push_back (word);
      continue;
    }

    for (auto iter = words->begin (); iter != words->end (); ++iter) {
      cmp_t ret = string_cmp (*iter, word);

      if (ret == cmp_t::SAME) {
        break;
      } else if (ret == cmp_t::BEFORE) {
        words->insert (iter, word);
        break;
      }
    }

    if (string_cmp (words->back (), word) == cmp_t::AFTER) {
      words->push_back (word);
    }
  }

  for (auto iter = words_by_len.begin (); iter != words_by_len.end (); ++iter) {
    if (iter->empty ())
      continue;
    for (auto i = iter->begin (); i != iter->end (); ++i) {
      std::cout << *i << "\n";
    }
  }

  return 0;
}

cmp_t
string_cmp (std::string &at, std::string &in)
{
  size_t at_len = at.length ();
  cmp_t ret = cmp_t::SAME;

  if (at == in) {
    ret = cmp_t::SAME;
  } else {
    for (size_t i = 0; i < at_len; ++i) {
      if (in[i] < at[i]) {
        ret = cmp_t::BEFORE;
        break;
      } else if (in[i] > at[i]) {
        ret = cmp_t::AFTER;
        break;
      }
    }
  }

  return ret;
}
