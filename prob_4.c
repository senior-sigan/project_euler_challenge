/**
 * Project Euler: Problem 4: Largest palindrome product
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is
 * 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two n-digit numbers.
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>

int is_palindrom(int num) {
  int n = num;
  int rev = 0;
  while (n != 0) {
    rev = rev * 10 + (n % 10);
    n /= 10;
  }
  return rev == num;
}

int largestPalindromeProduct(int n) {
  int max_n = pow(10, n);      // 100
  int min_n = pow(10, n - 1);  // 10

  int largest_palindrom = 0;

  for (int i = min_n; i < max_n; i++) {
    for (int j = min_n; j < max_n; j++) {
      int tmp = i * j;
      if (is_palindrom(tmp) && tmp > largest_palindrom) {
        largest_palindrom = tmp;
      }
    }
  }
  return largest_palindrom;
}

int main(void) {
  assert(is_palindrom(13) == 0);
  assert(is_palindrom(131) == 1);
  assert(is_palindrom(1331) == 1);

  assert(largestPalindromeProduct(2) == 9009);
  assert(largestPalindromeProduct(3) == 906609);

  return 0;
}
