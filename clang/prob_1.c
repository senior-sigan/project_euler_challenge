/**
 * Project Euler: Problem 1: Multiples of 3 and 5
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 * get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below the provided parameter
 * value number.
 */

#include <assert.h>

int multiplesOf3and5(int number) {
  int accum = 0;
  for (int i = 0; i < number; i++) {
    if ((i % 3 == 0) || (i % 5 == 0)) {
      accum += i;
    }
  }
  return accum;
}

int main(void) {
  assert(multiplesOf3and5(10) == 23);
  assert(multiplesOf3and5(49) == 543);
  assert(multiplesOf3and5(1000) == 233168);
  assert(multiplesOf3and5(8456) == 16687353);
  assert(multiplesOf3and5(19564) == 89301183);
}
