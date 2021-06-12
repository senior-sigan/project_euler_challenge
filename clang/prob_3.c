/**
 * Project Euler: Problem 3: Largest prime factor
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the given number?
 */

#include <assert.h>
#include <stdio.h>

long divide_until_possible(long number, long delim) {
  while (number % delim == 0) {
    number /= delim;
  }
  return number;
}

long largestPrimeFactor(long number) {
  long last_factor = 1;
  for (long i = 2; i * i <= number; i++) {
    if (number % i == 0) {
      last_factor = i;
      number = divide_until_possible(number, i);
    }
  }
  if (number == 1) return last_factor;
  return number;
}

int main(void) {
  assert(largestPrimeFactor(2) == 2);
  assert(largestPrimeFactor(3) == 3);
  assert(largestPrimeFactor(5) == 5);
  assert(largestPrimeFactor(7) == 7);
  assert(largestPrimeFactor(8) == 2);
  assert(largestPrimeFactor(13195) == 29);
  assert(largestPrimeFactor(600851475143) == 6857);
}
