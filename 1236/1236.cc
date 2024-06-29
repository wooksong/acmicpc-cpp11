#include <iostream>
#include <unordered_map>

std::unordered_map<int, bool> dict_rows;
std::unordered_map<int, bool> dict_cols;

int
main ()
{
  int R, C;
  int num_securities;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> R >> C;
  std::cin.ignore ();

  for (int i = 0; i < R; ++i) {
    std::string each_row;

    std::getline (std::cin, each_row);
    for (int j = 0; j < C; ++j) {
      if (each_row[j] == 'X') {
        dict_rows[i] = true;
        dict_cols[j] = true;
      }
    }
  }

  num_securities = 0;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (dict_rows.find (i) != dict_rows.end ()
          || dict_cols.find (j) != dict_cols.end ()) {
        continue;
      }
      dict_rows[i] = true;
      dict_cols[j] = true;

      num_securities++;
    }
  }

  for (int i = 0; i < R; ++i) {
    if (dict_rows.find (i) == dict_rows.end ()) {
      dict_rows[i] = true;
      num_securities++;
    }
  }

  for (int i = 0; i < C; ++i) {
    if (dict_cols.find (i) == dict_cols.end ()) {
      dict_cols[i] = true;
      num_securities++;
    }
  }

  std::cout << num_securities << "\n";

  return 0;
}
