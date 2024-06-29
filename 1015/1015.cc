#include <iostream>
#include <vector>

constexpr int MAX_ELEMENTS = 1001;

struct Element {
  int m_idx;
  int m_val;
  bool m_sorted;

  friend bool operator== (Element &lhs, Element &rhs);
  friend bool operator!= (Element &lhs, Element &rhs);
  friend bool operator<(Element &lhs, Element &rhs);
  friend bool operator> (Element &lhs, Element &rhs);

  Element ()
  {
    m_idx = -1;
    m_val = -1;
    m_sorted = false;
  };

  Element (int idx, int val)
  {
    m_idx = idx;
    m_val = val;
    m_sorted = true;
  }

  void show ()
  {
    std::cout << "m_idx = " << m_idx << ", m_val = " << m_val << "\n";
  }
};

std::vector<Element> tmp = std::vector<Element> (MAX_ELEMENTS);

void merge (std::vector<Element> &elements, int s, int m, int e);
void sort (std::vector<Element> &elements, int s, int e);

int
main ()
{
  int N;
  std::vector<Element> v;

  // freopen("input.txt", "r", stdin);
  std::cin >> N;

  v = std::vector<Element> (N);

  for (int i = 0; i < N; ++i) {
    int elmnt;

    std::cin >> elmnt;
    v[i] = Element (i, elmnt);
  }

  sort (v, 0, N);

  for (int i = 0; i < N; ++i) {
    if (v[i].m_sorted) {
      tmp[v[i].m_idx].m_idx = i;
      v[i].m_sorted = false;
    }
  }
  for (int i = 0; i < N; ++i) {
    std::cout << tmp[i].m_idx << " ";
  }

  std::cout << "\n";

  return 0;
}

bool
operator== (Element &lhs, Element &rhs)
{
  if (lhs.m_val == rhs.m_val && lhs.m_idx == rhs.m_idx)
    return true;
  return false;
}

bool
operator!= (Element &lhs, Element &rhs)
{
  return !(lhs == rhs);
}

bool
operator<(Element &lhs, Element &rhs)
{
  if (lhs.m_val < rhs.m_val)
    return true;
  if (lhs.m_val == rhs.m_val) {
    return lhs.m_idx < rhs.m_idx;
  }
  return false;
}

bool
operator> (Element &lhs, Element &rhs)
{
  return ((lhs != rhs) && !(lhs < rhs));
}

void
merge (std::vector<Element> &elements, int s, int m, int e)
{
  int i, j, pos;

  i = s;
  j = m;
  pos = i;
  while (i < m && j < e) {
    if (elements[i] < elements[j]) {
      elements[j].m_sorted = true;
      tmp[pos++] = elements[i++];
    } else {
      tmp[pos++] = elements[j++];
      elements[j].m_sorted = true;
    }
  }

  for (int ii = i; ii < m; ++ii) {
    tmp[pos++] = elements[ii];
  }

  for (int jj = j; jj < e; ++jj) {
    tmp[pos++] = elements[jj];
  }

  for (i = s; i < e; ++i) {
    elements[i] = tmp[i];
  }
}

void
sort (std::vector<Element> &elements, int s, int e)
{
  int m;

  if (e - s <= 1) {
    return;
  }
  m = (e - s) / 2 + s;

  sort (elements, s, m);
  sort (elements, m, e);
  merge (elements, s, m, e);
}
