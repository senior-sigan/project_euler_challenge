/**
 * Project Euler: Problem 6: Sum square difference
 * The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640. Find the difference
 * between the sum of the squares of the first n natural numbers and the square
 * of the sum.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

int64_t sum_square_difference(int64_t n) {
  int64_t sum_sq = 0;
  int64_t sum = 0;

  for (int64_t i = 1; i <= n; i++) {
    sum += i;
    sum_sq += i * i;
  }

  return sum * sum - sum_sq;
}

int main() {
  assert(sum_square_difference(10) == 2640);
  assert(sum_square_difference(20) == 41230);
  assert(sum_square_difference(100) == 25164150);
  return 0;
}
