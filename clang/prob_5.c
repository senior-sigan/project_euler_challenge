/**
 * Project Euler: Problem 5: Smallest multiple
 * 2520 is the smallest number that can be divided by each of the numbers from 1
 * to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to n?
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int how_deep_div(int n, int d) {
  int count = 0;
  while (n % d == 0) {
    count++;
    n /= d;
  }
  return count;
}

int smallestMult(int n) {
  int* sieve = (int*)calloc(n - 1, sizeof(int));
  // n = 9
  // [2 3 4 5 6 7 8 9] len = n - 1 = 8
  // [1 1 1 1 1 1 1 1]
  for (int i = 0; i < n - 1; i++) {
    sieve[i] = 1;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int delim = i + 2;
      int target = j + 2;
      if ((sieve[j] != 0) && (target % delim == 0)) {
        int div_pow = how_deep_div(target, delim);
        if (sieve[i] < div_pow) {
          sieve[i] = div_pow;
        }
        sieve[j] -= 1;
      }
    }
  }

  int num = 1;

  for (int i = 0; i < n - 1; i++) {
    if (sieve[i] > 0) {
      num *= pow(i + 2, sieve[i]);
    }
  }
  free(sieve);
  return num;
}

int main(void) {
  assert(smallestMult(5) == 60);
  assert(smallestMult(7) == 420);
  assert(smallestMult(10) == 2520);
  assert(smallestMult(13) == 360360);
  assert(smallestMult(20) == 232792560);
  return 0;
}
