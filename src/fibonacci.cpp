#include "fibonacci.h"

FibonacciResult fibonacci(int n) {
  if (n == 0) {
    return {0, 1};
  }
  int fk, fk1;
  std::tie(fk, fk1) = fibonacci(n >> 1);
  int fn = fk * (2 * fk1 - fk);
  int fn1 = fk * fk + fk1 * fk1;
  if (n & 1) {
    return {fn1, fn+fn1};
  } else {
    return {fn, fn1};
  }
}
