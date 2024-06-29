#include <iostream>
#include <vector>

struct Count {
  int32_t card_num;
  uint32_t cnt;

  Count ()
  {
    this->card_num = 0;
    this->cnt = 0;
  }

  Count (int32_t n)
  {
    this->card_num = n;
    this->cnt = 0;
  }

  Count (int32_t n, uint32_t c)
  {
    this->card_num = n;
    this->cnt = c;
  }

  void show ()
  {
    std::cout << "n = " << this->card_num << ", cnt = " << this->cnt << "\n";
  }
};

std::vector<int32_t> cards;
std::vector<int32_t> tmp;

void merge (size_t l, size_t m, size_t r);
void sort (size_t l, size_t r);
size_t count (std::vector<int32_t> *sv, std::vector<Count> &v);
uint32_t binary_search (std::vector<Count> &v, size_t l, size_t r, int32_t val);

int
main ()
{
  size_t N, M, num_unique_cards;
  std::vector<Count> cv;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  // freopen("input.txt", "r", stdin);

  std::cin >> N;
  cards = std::vector<int32_t> (N);
  tmp = std::vector<int32_t> (N);
  for (size_t i = 0; i < N; ++i) {
    std::cin >> cards[i];
  }

  sort (0, N);
  num_unique_cards = count (&cards, cv);

  std::cin >> M;
  for (size_t i = 0; i < M; ++i) {
    int32_t f;

    std::cin >> f;
    std::cout << binary_search (cv, 0, num_unique_cards, f) << " ";
  }
  std::cout << "\n";
  return 0;
}

void
merge (size_t l, size_t m, size_t r)
{
  size_t i, j, pos;

  i = l;
  j = m;
  pos = l;
  while (i < m && j < r) {
    if (cards[i] < cards[j]) {
      tmp[pos++] = cards[i++];
    } else {
      tmp[pos++] = cards[j++];
    }
  }

  for (; i < m; ++i) {
    tmp[pos++] = cards[i];
  }

  for (; j < r; ++j) {
    tmp[pos++] = cards[j];
  }

  for (i = l; i < r; ++i) {
    cards[i] = tmp[i];
  }
}

void
sort (size_t l, size_t r)
{
  size_t m;

  if ((r - l) <= 1)
    return;

  m = (r - l) / 2 + l;
  sort (l, m);
  sort (m, r);
  merge (l, m, r);
}

uint32_t
binary_search (std::vector<Count> &v, size_t l, size_t r, int32_t val)
{

  if ((r - l) == 1) {
    if (v[l].card_num == val) {
      return v[l].cnt;
    }
  } else {
    size_t m = (r - l) / 2 + l;

    if (v[m].card_num == val) {
      return v[m].cnt;
    } else if (v[m].card_num > val) {
      return binary_search (v, l, m, val);
    } else {
      return binary_search (v, m, r, val);
    }
  }

  return 0;
}

size_t
count (std::vector<int32_t> *sv, std::vector<Count> &v)
{
  uint32_t cnt;
  int32_t prev = sv->at (0);

  cnt = 1;
  for (size_t i = 1; i < sv->size (); ++i) {
    if (prev != sv->at (i)) {
      v.push_back (Count (prev, cnt));
      cnt = 1;
      prev = sv->at (i);
    } else {
      cnt++;
    }
  }

  v.push_back (Count (prev, cnt));

  return v.size ();
}
