#include "catch2/catch_amalgamated.hpp"
#include "compose.h"

TEST_CASE("compose"){
  SECTION("runs the right function followed by the left") {
    auto add1 = [](int x) { return x + 1; };
    auto multiply2 = [](int x) { return x * 2; };
    REQUIRE( compose<int, int, int>(multiply2, add1)(1) == 4 );
  }
}
