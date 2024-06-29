#include <iostream>
#include <vector>

constexpr uint64_t HASH_BUCKET = 100007;
constexpr uint64_t HASH_MUL = 31;

uint64_t gen_hash (std::string str);

int
main ()
{
  int N, P;
  int score, score_w, score_l, score_goal;
  std::vector<char> hash_table;

  // freopen("input.txt", "r", stdin);
  std::cin >> N >> P;
  std::cin >> score_w >> score_l >> score_goal;

  hash_table = std::vector<char> (HASH_BUCKET, 'N');

  for (int i = 0; i < P; ++i) {
    std::string p_name;
    char p_res;

    std::cin >> p_name >> p_res;
    hash_table[gen_hash (p_name)] = p_res;
  }

  score = 0;
  for (int i = 0; i < N; ++i) {
    std::string p_name;
    uint64_t hash;
    std::cin >> p_name;
    hash = gen_hash (p_name);
    switch (hash_table[hash]) {
      case 'W':
        score += score_w;
        break;
      default:
      case 'L':
        score -= score_l;
        if (score < 0) {
          score = 0;
        }
        break;
    }
    if (score >= score_goal) {
      std::cout << "I AM NOT IRONMAN!!\n";
      break;
    }
  }

  if (score < score_goal) {
    std::cout << "I AM IRONMAN!!\n";
  }

  return 0;
}

uint64_t
gen_hash (std::string str)
{
  uint64_t hash;
  uint64_t mul;

  hash = 0;
  mul = 1;
  for (auto iter = str.begin (); iter != str.end (); ++iter) {
    hash += ((*iter - 'A') * mul);
    mul *= HASH_MUL;
    mul %= HASH_BUCKET;
    hash %= HASH_BUCKET;
  }

  return hash;
}
