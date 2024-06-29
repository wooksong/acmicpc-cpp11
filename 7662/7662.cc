#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

int
main ()
{
  int T;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
  std::unordered_map<int, int> dict;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);

  // freopen("input.txt", "r", stdin);
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int K;

    std::cin >> K;
    min_heap = std::priority_queue<int, std::vector<int>, std::greater<int>> ();
    max_heap = std::priority_queue<int, std::vector<int>, std::less<int>> ();
    dict.clear ();
    for (int k = 0; k < K; ++k) {
      char cmd;
      int val;

      std::cin >> cmd >> val;
      if (cmd == 'I') {
        if (dict.find (val) == dict.end ()) {
          dict[val] = 1;
        } else {
          dict[val]++;
        }
        max_heap.push (val);
        min_heap.push (val);
      } else {
        if (val == 1) {
          while (!max_heap.empty () && dict[max_heap.top ()] == 0) {
            max_heap.pop ();
          }
          if (!max_heap.empty ()) {
            dict[max_heap.top ()]--;
            max_heap.pop ();
          }
        } else {
          while (!min_heap.empty () && dict[min_heap.top ()] == 0) {
            min_heap.pop ();
          }
          if (!min_heap.empty ()) {
            dict[min_heap.top ()]--;
            min_heap.pop ();
          }
        }
      }
    }
    while (!max_heap.empty () && dict[max_heap.top ()] == 0) {
      max_heap.pop ();
    }

    while (!min_heap.empty () && dict[min_heap.top ()] == 0) {
      min_heap.pop ();
    }
    if (max_heap.empty () || min_heap.empty ()) {
      std::cout << "EMPTY\n";
    } else {
      std::cout << max_heap.top () << " " << min_heap.top () << "\n";
    }
  }
  return 0;
}
