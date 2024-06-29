#include <iostream>

int
main ()
{
  uint32_t N;
  uint32_t y_sum;
  uint32_t m_sum;

  std::cin >> N;
  y_sum = 0;
  m_sum = 0;
  for (uint32_t i = 0; i < N; ++i) {
    uint32_t each_call;

    std::cin >> each_call;

    y_sum += (((each_call / 30) + 1) * 10);
    m_sum += (((each_call / 60) + 1) * 15);
  }

  if (y_sum == m_sum) {
    printf ("Y M %u\n", y_sum);
  } else if (y_sum > m_sum) {
    printf ("M %u\n", m_sum);
  } else {
    printf ("Y %u\n", y_sum);
  }
}
