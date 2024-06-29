#include <iostream>
#include <vector>

constexpr int MAX_SIZE = 100001;

class Stack
{
  public:
  Stack ()
  {
    m_pos = 0;
    m_size = 0;
  }
  void push (int e);
  int pop ();
  bool is_empty ();
  int size ();

  private:
  int m_pos;
  int m_size;
  int m_data[MAX_SIZE];
};

void
Stack::push (int e)
{
  ++this->m_size;
  this->m_data[this->m_pos++] = e;
}

int
Stack::pop ()
{
  if (is_empty ()) {
    return -1;
  }
  --this->m_size;
  return this->m_data[--this->m_pos];
}

bool
Stack::is_empty ()
{
  return (this->m_size == 0);
}
int
Stack::size ()
{
  return this->m_size;
}

int
main ()
{
  int N, popped, cnt;
  bool impossible = false;
  std::vector<char> ans;
  Stack stck;

  // freopen("input.txt", "r", stdin);
  std::cin >> N;

  for (int i = 1, tmp = 1; i <= N; ++i) {
    int n;

    std::cin >> n;
    if (i <= n) {
      cnt = 0;
      while (tmp <= n) {
        stck.push (tmp++);
        cnt++;
      }
      popped = stck.pop ();
      if (popped != n) {
        impossible = true;
        break;
      }
      for (int j = 0; j < cnt; ++j) {
        ans.push_back ('+');
      }
      ans.push_back ('-');
    } else {
      cnt = 0;
      do {
        popped = stck.pop ();

        cnt++;
        if (popped == n) {
          break;
        }
      } while (!stck.is_empty ());

      if (popped == -1) {
        impossible = true;
        break;
      }
      for (int j = 0; j < cnt; ++j) {
        ans.push_back ('-');
      }
    }
  }

  if (impossible) {
    std::cout << "NO\n";
  } else {
    for (char c : ans) {
      std::cout << c << "\n";
    }
  }

  return 0;
}
