#include <iostream>
#include <memory.h>

constexpr int MAX_STUDENTS = 31;
constexpr int MAX_GOOD_STUDENTS = 28;

int
main ()
{
  int students[MAX_STUDENTS];

  // freopen("input.txt", "r", stdin);

  memset (students, 0, sizeof (students[0]) * MAX_STUDENTS);

  for (int i = 0; i < MAX_GOOD_STUDENTS; ++i) {
    int num = 0;

    std::cin >> num;
    students[num] = 1;
  }

  for (int i = 1; i < MAX_STUDENTS; ++i) {
    if (!students[i]) {
      printf ("%d\n", i);
    }
  }

  return 0;
}
