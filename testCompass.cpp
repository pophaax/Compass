#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "Compass.h"
#include "HMC6343.h"
#include "MockCompass.h"

using namespace std;
TEST_CASE("CompassTest real compass")
{
	SECTION("test init") {
		HMC6343 c;
		Compass* compass = &c;
		REQUIRE(compass->init());
	}
}
TEST_CASE("CompassTest mock compass")
{
	SECTION("test init") {
		MockCompass c;
		Compass* compass = &c;
		REQUIRE(compass->init());
	}
}
