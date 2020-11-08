#include "catch2/catch_amalgamated.hpp"
#include "fibonacci.h"

TEST_CASE("Fibonacci"){
  REQUIRE(fibonacci(0).first == 0);
  REQUIRE(fibonacci(1).first == 1);
  REQUIRE(fibonacci(2).first == 1);
  REQUIRE(fibonacci(10).first == 55);
  REQUIRE(fibonacci(17).first == 1597);
  REQUIRE(fibonacci(18).first == 2584);
}
