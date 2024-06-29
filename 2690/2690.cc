#include <iostream>

uint32_t gcd (uint32_t left, uint32_t right);

int
main ()
{
  uint32_t nums[2], val_gcd;

  std::cin >> nums[0] >> nums[1];

  val_gcd = gcd (nums[0], nums[1]);
  std::cout << val_gcd << "\n" << nums[0] * nums[1] / val_gcd << "\n";

  return 0;
}

uint32_t
gcd (uint32_t left, uint32_t right)
{
  if (right == 0)
    return left;
  return gcd (right, left % right);
}
