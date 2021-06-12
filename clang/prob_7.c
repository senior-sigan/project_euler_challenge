/**
 * Project Euler: Problem 7: 10001st prime
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the nth prime number?
 */

#include <assert.h>
#include <stdlib.h>

int is_prime(long number, const long* primes, long len) {
  for (long i = 0; i < len; i++) {
    if (number % primes[i] == 0) {
      return 0;
    }
  }

  return 1;
}

long nth_prime(long n) {
  long* primes = calloc(n, sizeof(long));
  long len = 0;
  long number = 2;
  while (len < n) {
    if (is_prime(number, primes, len)) {
      primes[len] = number;
      len++;
    }
    number++;
  }

  return primes[len - 1];
}

int main() {
  assert(nth_prime(6) == 13);
  assert(nth_prime(10) == 29);
  assert(nth_prime(100) == 541);
  assert(nth_prime(1000) == 7919);
  assert(nth_prime(10001) == 104743);
}
