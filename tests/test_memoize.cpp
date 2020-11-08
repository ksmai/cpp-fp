#include "catch2/catch_amalgamated.hpp"
#include "memoize.h"

TEST_CASE("memoize"){
  SECTION("does not call a function more than once"){
    int calls = 0;
    auto fn = fp::memoize<int, int>([&calls](int x) { ++calls; return x; });
    REQUIRE( fn(42) == 42 );
    REQUIRE( calls == 1 );
    REQUIRE( fn(42) == 42 );
    REQUIRE( calls == 1 );
  }
}
