#include <cstring>
#include <iostream>
#include <map>

const size_t LEN_NAME_TREE = 31;

int
main ()
{
  std::map<std::string, size_t> map_tree_cnt;
  size_t cnt;
  char buf[31];

  // freopen ("input.txt", "r", stdin);

  cnt = 0;
  while (fgets (buf, LEN_NAME_TREE, stdin) != nullptr) {
    buf[strlen (buf) - 1] = '\0';
    {
      std::string tree (buf);

      if (map_tree_cnt.find (std::string (tree)) == map_tree_cnt.end ()) {
        map_tree_cnt[tree] = 1;
      } else {
        ++map_tree_cnt[tree];
      }
    }

    ++cnt;
  }

  for (auto it : map_tree_cnt) {
    double percents = (static_cast<double> (it.second) / cnt) * 100;
    printf ("%s %.4lf\n", it.first.c_str (), percents);
  }

  return 0;
}
