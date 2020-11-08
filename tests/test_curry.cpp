#include "catch2/catch_amalgamated.hpp"
#include "curry.h"

TEST_CASE("curry"){
  SECTION("allows 2 arguments to be provided separately"){
    auto add = fp::curry<int, int, int>([](int x, int y) { return x + y; });
    REQUIRE( add(1)(2) == 3 );
  }
}
