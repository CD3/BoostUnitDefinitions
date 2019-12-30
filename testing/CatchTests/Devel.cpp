#include "catch.hpp"

#include <BoostUnitDefinitions/Units.hpp>

/**
 * This file is used for developement. As new classes are created, small tests
 * are written here so that we can try to compile and use them.
 */


TEST_CASE("General", "[devel]")
{
  using namespace boost;
  using namespace boost::units;

  SECTION("Straight boost")
  {
    quantity<si::length> L(10*si::meter);

    CHECK( quantity<cgs::length>(L).value() == 1000 );
  }

  SECTION("Our definitions")
  {
    quantity<t::m> L(10*i::m);

    CHECK( quantity<t::cm>(L).value() == 1000 );
  }

  SECTION("Radiant Exposure")
  {
    quantity<t::J_cm_n2> H(2 * i::mJ_cm_n2);

    CHECK( H.value() == 0.002);
  }
}
