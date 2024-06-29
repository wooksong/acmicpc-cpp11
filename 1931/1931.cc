#include <iostream>
#include <vector>

constexpr int MAX_NUM_MEETINGS = 100001;

struct Meeting {
  int s_time;
  int e_time;
};

Meeting tmp_v[MAX_NUM_MEETINGS];

void merge (std::vector<Meeting> &v, int idx_s, int idx_m, int idx_e);
void sort (std::vector<Meeting> &v, int idx_s, int idx_e);

int
main ()
{
  std::vector<Meeting> meetings;
  int num_meetings = 0;
  Meeting *cur_meeting;
  int N;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  // freopen("input.txt", "r", stdin);

  std::cin >> N;
  meetings = std::vector<Meeting> (N);
  for (int i = 0; i < N; ++i) {
    std::cin >> meetings[i].s_time >> meetings[i].e_time;
  }

  sort (meetings, 0, N);

  num_meetings = 1;
  cur_meeting = &meetings[0];

  for (int i = 1; i < N; ++i) {
    if (meetings[i].s_time < cur_meeting->e_time)
      continue;
    cur_meeting = &meetings[i];
    num_meetings++;
  }

  std::cout << num_meetings << "\n";
}

void
merge (std::vector<Meeting> &v, int idx_s, int idx_m, int idx_e)
{
  int i = idx_s;
  int j = idx_m;
  int pos = idx_s;

  while (i < idx_m && j < idx_e) {
    if (v[i].e_time == v[j].e_time) {
      if (v[i].s_time <= v[j].s_time) {
        tmp_v[pos++] = v[i++];
      } else {
        tmp_v[pos++] = v[j++];
      }
    } else if (v[i].e_time < v[j].e_time) {
      tmp_v[pos++] = v[i++];
    } else {
      tmp_v[pos++] = v[j++];
    }
  }

  while (i < idx_m) {
    tmp_v[pos++] = v[i++];
  }
  while (j < idx_e) {
    tmp_v[pos++] = v[j++];
  }

  for (i = idx_s; i < idx_e; ++i) {
    v[i] = tmp_v[i];
  }
}

void
sort (std::vector<Meeting> &v, int idx_s, int idx_e)
{
  int idx_m;

  if ((idx_e - idx_s) == 1)
    return;

  idx_m = idx_s + (idx_e - idx_s) / 2;

  sort (v, idx_s, idx_m);
  sort (v, idx_m, idx_e);
  merge (v, idx_s, idx_m, idx_e);
}
