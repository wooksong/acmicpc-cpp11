#include <algorithm>
#include <iostream>
#include <vector>

struct Work {
  int required;
  int deadline;
};

struct {
  bool operator() (Work &lhs, Work &rhs)
  {
    if (lhs.deadline == rhs.deadline) {
      return lhs.required > rhs.required;
    }
    return lhs.deadline < rhs.deadline;
  }
} DeadlineComp;

int
main ()
{
  std::vector<Work> works;
  int N, wtime;
  bool found = false;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);

  // freopen("input.txt", "r", stdin);
  std::cin >> N;

  works = std::vector<Work> (N);
  for (int i = 0; i < N; ++i) {
    std::cin >> works[i].required >> works[i].deadline;
  }

  std::sort (works.begin (), works.end (), DeadlineComp);
  wtime = works[0].deadline - works[0].required;
  while (wtime >= 0) {
    int timeline = wtime;
    int i;

    for (i = 0; i < N; ++i) {
      if ((timeline + works[i].required) > works[i].deadline) {
        wtime--;
        break;
      }
      timeline += works[i].required;
    }

    if (i == N) {
      found = true;
      break;
    }
  }

  std::cout << (found ? wtime : -1) << "\n";

  return 0;
}
