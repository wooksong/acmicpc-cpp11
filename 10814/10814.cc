#include <algorithm>
#include <iostream>
#include <vector>

constexpr uint32_t INVAL_AGE = 0;
constexpr uint32_t INVAL_ORDER = 0;

struct Member {
  uint32_t age;
  uint32_t order;
  std::string name;

  Member ()
  {
    this->age = INVAL_AGE;
    this->order = INVAL_ORDER;
  }

  Member (uint32_t age, uint32_t order, std::string name)
  {
    this->age = age;
    this->order = order;
    this->name = name;
  }

  void show (bool with_order)
  {
    if (with_order) {
      std::cout << this->order << " ";
    }
    std::cout << this->age << " " << this->name << "\n";
  }

  friend bool operator== (Member &lhs, Member &rhs);
  friend bool operator!= (Member &lhs, Member &rhs);
  friend bool operator<(Member &lhs, Member &rhs);
  friend bool operator> (Member &lhs, Member &rhs);
};

std::vector<Member> tmp_members;
std::vector<Member> members;

void sort (size_t l, size_t r);
void merge (size_t l, size_t m, size_t r);

int
main ()
{
  size_t N;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (0);
  std::cout.tie (0);
  // freopen("input.txt", "r", stdin);
  std::cin >> N;

  members = std::vector<Member> (N);
  tmp_members = std::vector<Member> (N);

  for (uint32_t i = 0; i < N; ++i) {
    Member m;

    std::cin >> m.age >> m.name;
    m.order = i + 1;
    members[i] = m;
    tmp_members[i] = m;
  }

  sort (0, N);
  for (uint32_t i = 0; i < N; ++i) {
    members[i].show (false);
  }
  return 0;
}

void
merge (size_t l, size_t m, size_t r)
{
  size_t i = l, j = m;
  size_t pos = l;

  while (i < m && j < r) {
    if (members[i] < members[j]) {
      tmp_members[pos++] = members[i++];
    } else {
      tmp_members[pos++] = members[j++];
    }
  }

  for (size_t li = i; li < m; ++li) {
    tmp_members[pos++] = members[li];
  }

  for (size_t mi = j; mi < r; ++mi) {
    tmp_members[pos++] = members[mi];
  }

  for (i = l; i < r; ++i) {
    members[i] = tmp_members[i];
  }
}

void
sort (size_t l, size_t r)
{
  size_t middle;

  if ((r - l) <= 1) {
    return;
  }

  middle = (r - l) / 2 + l;
  sort (l, middle);
  sort (middle, r);
  merge (l, middle, r);
}

bool
operator== (Member &lhs, Member &rhs)
{
  if (lhs.age == rhs.age && lhs.name == rhs.name && lhs.order == rhs.order)
    return true;
  return false;
}

bool
operator!= (Member &lhs, Member &rhs)
{
  return !(lhs == rhs);
}

bool
operator<(Member &lhs, Member &rhs)
{
  if (lhs != rhs) {
    if (lhs.age < rhs.age)
      return true;
    if ((lhs.age == rhs.age) && (lhs.order < rhs.order))
      return true;
  }
  return false;
}

bool
operator> (Member &lhs, Member &rhs)
{
  return (!(lhs == rhs) && !(lhs < rhs));
}
