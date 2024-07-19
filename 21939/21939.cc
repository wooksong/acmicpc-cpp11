#include <iostream>
#include <set>
#include <vector>

const std::string CMD_RECOM ("recommend");
const std::string CMD_ADD ("add");
const std::string CMD_SOLVED ("solved");

using problem_t = std::pair<int, int>;

std::vector<int> problems;

int
main ()
{
  std::set<problem_t, std::greater<problem_t>> problems_asc;
  int N;

  problems = std::vector<int> (100000, -1);

  freopen ("input.txt", "r", stdin);
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int id, lv;

    std::cin >> id >> lv;

    problems[id] = lv;
    problems_asc.insert ({ lv, id });
  }

  {
    int n_cmds;

    std::cin >> n_cmds;

    for (int i = 0; i < n_cmds; ++i) {
      std::string cmd;

      std::cin >> cmd;

      if (cmd == CMD_RECOM) {
        int lv;
        std::cin >> lv;

        switch (lv) {
          case 1:
            {
              auto it = problems_asc.begin ();
              std::cout << (*it).second << "\n";
              break;
            }

          case -1:
            {
              auto it = problems_asc.rbegin ();
              std::cout << (*it).second << "\n";
              break;
            }

          default:
            break;
        }
      } else if (cmd == CMD_ADD) {
        int id, lv;
        std::cin >> id >> lv;

        problems[id] = lv;
        problems_asc.insert ({ lv, id });
      } else {
        int id;

        std::cin >> id;
        int lv = problems[id];

        problems_asc.erase ({ lv, id });
        problems[id] = 0;
      }
    }
  }
  return 0;
}
