#include <algorithm>
#include <iostream>
#include <vector>

constexpr size_t MAX_NUM_PEOPLE = 500001;

struct Person {
  uint64_t hash;
  std::string name;
};

uint64_t
gen_hash (std::string name)
{
  const uint64_t mul = 31;
  const uint64_t dividor = 1000003;
  uint64_t m = 1;
  uint64_t hash = 0;

  for (size_t i = 0; i < name.length (); ++i) {
    hash += (static_cast<uint64_t> (name[i] - '0') * m) % dividor;
    m *= mul;
    m %= dividor;
  }

  return hash;
}

int
main ()
{
  int num_people_never_heard;
  int num_people_never_seen;

  std::vector<std::vector<Person>> table = std::vector<std::vector<Person>> (MAX_NUM_PEOPLE);
  std::vector<std::string> ans;

  // freopen("input.txt", "r", stdin);

  std::cin >> num_people_never_heard >> num_people_never_seen;
  for (int i = 0; i < num_people_never_heard; ++i) {
    std::string name;
    std::vector<Person> *v;
    Person p;

    std::cin >> p.name;
    p.hash = gen_hash (p.name);
    v = &table[p.hash % MAX_NUM_PEOPLE];
    v->push_back (p);
  }

  for (int i = 0; i < num_people_never_seen; ++i) {
    std::vector<Person> *v;
    std::string name;
    uint64_t hash;

    std::cin >> name;
    hash = gen_hash (name);
    v = &table[hash % MAX_NUM_PEOPLE];

    for (auto iter = v->begin (); iter != v->end (); ++iter) {
      if ((*iter).name == name) {
        ans.push_back (name);
      }
    }
  }

  std::cout << ans.size () << "\n";
  std::sort (ans.begin (), ans.end ());
  for (auto iter = ans.begin (); iter != ans.end (); ++iter) {
    std::cout << *iter << "\n";
  }

  return 0;
}
