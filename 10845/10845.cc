#include <iostream>

constexpr size_t MAX_NUMS_CMD = 10001;
constexpr size_t INVAL_POS = MAX_NUMS_CMD + 1;

class Queue
{
  public:
  Queue ()
  {
    m_size = 0;
    m_pos_front = INVAL_POS;
    m_pos_back = INVAL_POS;
  };

  bool empty ();
  size_t size ();
  int32_t front ();
  int32_t back ();
  void push (int32_t val);
  int32_t pop ();


  private:
  size_t m_size;
  int32_t m_data[MAX_NUMS_CMD];
  size_t m_pos_front;
  size_t m_pos_back;
};


bool
Queue::empty ()
{
  return (m_size == 0) ? true : false;
}

size_t
Queue::size ()
{
  return this->m_size;
}

void
Queue::push (int32_t val)
{
  if (this->empty ()) {
    this->m_pos_back = 0;
    this->m_pos_front = 0;
    this->m_data[m_pos_front] = val;
  } else {
    this->m_pos_back++;
    if (this->m_pos_back == MAX_NUMS_CMD) {
      this->m_pos_back = 0;
    }

    this->m_data[m_pos_back] = val;
  }
  this->m_size++;
}

int32_t
Queue::pop ()
{
  int32_t ret;

  if (this->empty ()) {
    return -1;
  }

  ret = this->m_data[this->m_pos_front++];
  if (this->m_pos_front == MAX_NUMS_CMD) {
    this->m_pos_front = 0;
  }

  this->m_size--;

  return ret;
}

int32_t
Queue::front ()
{
  if (this->empty ())
    return -1;
  return this->m_data[this->m_pos_front];
}

int32_t
Queue::back ()
{
  if (this->empty ())
    return -1;
  return this->m_data[this->m_pos_back];
}

int
main ()
{
  Queue q;
  uint32_t N;

  // freopen("input.txt", "r", stdin);
  std::cin >> N;

  for (uint32_t i = 0; i < N; ++i) {
    std::string cmd;

    std::cin >> cmd;
    if (cmd == "push") {
      int32_t val;

      std::cin >> val;
      q.push (val);
    } else if (cmd == "pop") {
      std::cout << q.pop () << "\n";
    } else if (cmd == "size") {
      std::cout << q.size () << "\n";
    } else if (cmd == "empty") {
      std::cout << (q.empty () ? 1 : 0) << "\n";
    } else if (cmd == "front") {
      std::cout << q.front () << "\n";
    } else if (cmd == "back") {
      std::cout << q.back () << "\n";
    }
  }
  return 0;
}
