#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int
main ()
{
  std::unordered_map<char, int> scores
      = { { 'L', 0 }, { 'O', 0 }, { 'V', 0 }, { 'E', 0 } };
  std::vector<std::pair<std::string, int>> answers;
  std::vector<std::string> team_names;
  std::string name;
  int num_candidates;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> name;
  for (char l : name) {
    if (scores.find (l) == scores.end ()) {
      continue;
    }

    ++scores[l];
  }
  std::cin >> num_candidates;

  team_names.reserve (num_candidates);
  for (int i = 0; i < num_candidates; ++i) {
    std::unordered_map<char, int> candidate_scores = scores;
    std::string candidate;

    std::cin >> candidate;
    team_names.push_back (candidate);
    for (char l : candidate) {
      if (candidate_scores.find (l) == candidate_scores.end ()) {
        continue;
      }

      ++candidate_scores[l];
    }
    {
      int score = 0;
      int L = candidate_scores['L'];
      int O = candidate_scores['O'];
      int V = candidate_scores['V'];
      int E = candidate_scores['E'];

      score = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
      answers.push_back ({ candidate, score });
    }
  }

  struct {
    bool operator() (std::pair<std::string, int> &lhs, std::pair<std::string, int> &rhs)
    {
      if (lhs.second > rhs.second) {
        return true;
      } else if (lhs.second == rhs.second) {
        return (lhs.first < rhs.first ? true : false);
      }

      return false;
    }
  } Comp;

  std::sort (answers.begin (), answers.end (), Comp);
  std::cout << answers[0].first << "\n";

  return 0;
}
