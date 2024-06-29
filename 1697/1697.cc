#include <deque>
#include <iostream>

constexpr int MAX_POINTS = 100001;
constexpr int NUM_MOVES = 3;

int visited[MAX_POINTS];
int moves[NUM_MOVES];

int bfs (int s, int k);
int
main ()
{
  int N, K;

  // freopen("input.txt", "r", stdin);

  std::cin >> N >> K;
  for (int i = 0; i < MAX_POINTS; ++i) {
    visited[i] = -1;
  }

  std::cout << bfs (N, K) << "\n";
  return 0;
}

int
bfs (int s, int k)
{
  std::deque<int> queue;

  queue.push_back (s);
  visited[s] = 0;

  while (!queue.empty ()) {
    int v = queue.front ();

    queue.pop_front ();
    moves[0] = v - 1;
    moves[1] = v + 1;
    moves[2] = 2 * v;

    if (v == k) {
      return visited[k];
    }

    for (int i = 0; i < NUM_MOVES; ++i) {
      int to = moves[i];

      if (to < 0 || to >= MAX_POINTS)
        continue;

      if (visited[to] == -1) {
        visited[to] = visited[v] + 1;
        queue.push_back (to);
      }
    }
  }

  return -1;
}
