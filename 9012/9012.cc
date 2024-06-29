#include <iostream>

constexpr size_t MAX_SIZE_PS = 51;

class Stack
{
  public:
  Stack ();
  void push (char p);
  char pop ();
  bool is_empty ();
  void clear ();

  private:
  size_t m_size;
  size_t m_pos;
  char m_data[MAX_SIZE_PS];
};

Stack::Stack ()
{
  this->m_pos = 0;
  this->m_size = 0;
}

void
Stack::push (char p)
{
  this->m_data[this->m_pos++] = p;
  this->m_size++;
}
char
Stack::pop ()
{
  this->m_size--;
  return this->m_data[--this->m_pos];
}

bool
Stack::is_empty ()
{
  return this->m_size == 0 ? true : false;
}
void
Stack::clear ()
{
  this->m_pos = 0;
  this->m_size = 0;
}
int
main ()
{
  uint32_t T;
  Stack stck;

  // freopen("input.txt", "r", stdin);
  std::cin >> T;

  for (uint32_t i = 0; i < T; ++i) {
    std::string ps;
    bool is_vps = true;

    std::cin >> ps;
    stck.clear ();
    for (auto iter = ps.begin (); iter != ps.end (); ++iter) {
      if (*iter == '(') {
        stck.push (*iter);
      } else {
        if (stck.is_empty ()) {
          is_vps = false;
          break;
        } else {
          stck.pop ();
        }
      }
    }

    if (!stck.is_empty ())
      is_vps = false;

    std::cout << (is_vps ? "YES\n" : "NO\n");
  }

  return 0;
}
