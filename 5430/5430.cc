#include <deque>
#include <iostream>

int
main ()
{
  std::deque<int> v;
  std::string p;
  int T;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  // freopen("input.txt", "r", stdin);

  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    std::string arr;
    bool is_reversed = false;
    bool is_error = false;
    size_t deque_size;
    size_t tmp_len;
    int n;

    p.clear ();
    v.clear ();
    arr.clear ();

    deque_size = 0;

    std::cin >> p;
    std::cin >> n;
    std::cin >> arr;

    if (n > 0) {
      size_t tmp_len = arr.length ();
      int mul = 10;
      int num;

      for (size_t i = 0; i < tmp_len; ++i) {
        switch (arr[i]) {
          case '[':
            num = 0;
            break;
          case ']':
          case ',':
            v.push_back (num);
            num = 0;
            break;
          default:
            num *= mul;
            num += (arr[i] - '0');
            break;
        }
      }
    }

    deque_size = v.size ();
    tmp_len = p.length ();
    for (size_t i = 0; i < tmp_len; ++i) {
      if (p[i] == 'R') {
        is_reversed = !is_reversed;
      } else {
        if (deque_size == 0) {
          is_error = true;
          break;
        }

        if (is_reversed) {
          v.pop_back ();
        } else {
          v.pop_front ();
        }
        --deque_size;
      }
    }

    if (is_error) {
      std::cout << "error\n";
    } else {
      size_t v_size = v.size ();

      std::cout << "[";
      if (!v.empty ()) {
        if (is_reversed) {
          for (size_t i = v_size; i != 1; --i) {
            std::cout << v[i - 1] << ",";
          }
          std::cout << v[0];
        } else {
          for (size_t i = 0; i < v_size - 1; ++i) {
            std::cout << v[i] << ",";
          }
          std::cout << v[v_size - 1];
        }
      }
      std::cout << "]\n";
    }
  }
  return 0;
}
