#include <iostream>
#include <vector>

struct Bulk {
  uint32_t weight;
  uint32_t height;
  uint32_t rank;
  uint32_t idx;

  Bulk ()
  {
    this->weight = 0;
    this->height = 0;
    this->rank = 0;
    this->idx = 0;
  }
  Bulk (uint32_t w, uint32_t h, uint32_t r, uint32_t i)
  {
    this->weight = w;
    this->height = h;
    this->rank = r;
    this->idx = i;
  }
};

bool operator> (Bulk &l, Bulk &r);

int
main ()
{
  int32_t N;
  std::vector<Bulk> bulk_info;
  std::vector<Bulk> bulk_ans;

  // freopen("input.txt", "r", stdin);

  std::cin >> N;
  bulk_ans = std::vector<Bulk> (N);
  for (int32_t i = 0; i < N; ++i) {
    int32_t x, y;

    std::cin >> x >> y;
    {
      Bulk tmp = Bulk (x, y, 0, i);
      std::vector<Bulk>::iterator iter;

      for (iter = bulk_info.begin (); iter != bulk_info.end (); ++iter) {
        if (tmp > *iter) {
          bulk_info.insert (iter, tmp);
          break;
        }
      }

      if (iter == bulk_info.end ())
        bulk_info.push_back (tmp);
    }
  }

  for (int32_t i = N - 1; i >= 0; --i) {
    uint32_t cnt = 0;

    for (int32_t j = 0; j < i; ++j) {
      if ((bulk_info[j] > bulk_info[i])) {
        cnt++;
      }
    }

    bulk_info[i].rank = cnt + 1;
    bulk_ans[bulk_info[i].idx].rank = cnt + 1;
  }

  for (size_t i = 0; i < bulk_ans.size (); ++i) {
    std::cout << bulk_ans[i].rank << " ";
  }
  std::cout << "\n";
  return 0;
}

bool
operator> (Bulk &l, Bulk &r)
{
  if ((l.height > r.height) && (l.weight > r.weight))
    return true;
  return false;
}
