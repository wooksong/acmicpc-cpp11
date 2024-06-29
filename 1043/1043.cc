#include <deque>
#include <iostream>
#include <vector>

std::vector<bool> members;
std::vector<std::vector<bool>> adj_mat;
std::vector<std::vector<int>> parties;

void bfs (int s);

int
main ()
{
  int num_mems, num_parties, num_liars, ans;

  freopen ("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> num_mems >> num_parties;
  std::cin >> num_liars;

  if (!num_liars) {
    std::cout << num_parties << "\n";
    return 0;
  }
  members = std::vector<bool> (num_mems + 1, false);
  adj_mat = std::vector<std::vector<bool>> (num_mems + 1, members);
  parties = std::vector<std::vector<int>> (num_parties + 1);

  for (int i = 0; i < num_liars; ++i) {
    int liar;

    std::cin >> liar;
    members[liar] = true;
  }

  for (int i = 0; i < num_parties; ++i) {
    std::vector<int> party_peple;
    int n;

    std::cin >> n;
    party_peple = std::vector<int> (n);
    for (int j = 0; j < n; ++j) {
      std::cin >> party_peple[j];
    }

    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        adj_mat[party_peple[j]][party_peple[k]] = true;
      }
    }

    parties[i] = party_peple;
  }

  for (int i = 1; i <= num_mems; ++i) {
    if (members[i])
      bfs (i);
  }

  ans = 0;
  for (int i = 0; i < num_parties; ++i) {
    bool found = true;
    for (auto iter = parties[i].begin (); iter != parties[i].end (); ++iter) {
      if (members[*iter]) {
        found = false;
        break;
      }
    }

    if (found) {
      ans++;
    }
  }

  std::cout << ans << "\n";

  return 0;
}

void
bfs (int s)
{
  std::vector<bool> *adj_arr;
  std::deque<int> dq;

  dq.push_back (s);
  while (!dq.empty ()) {
    int cur = dq.front ();
    int i;

    dq.pop_front ();
    members[cur] = true;
    adj_arr = &adj_mat[cur];
    i = 0;
    for (auto iter = adj_arr->begin (); iter != adj_arr->end (); ++iter, ++i) {
      if (i == cur)
        continue;

      if ((*iter) && (!members[i])) {
        dq.push_back (i);
      }
    }
  }
}
