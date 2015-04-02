#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <iostream>
#include "Compass.h"
#include "MockCompass.h"

using namespace std;
TEST_CASE("CompassTest")
{
	SECTION("Test Compass init true")
	{
		MockCompass mc(true, 1);
		Compass c(mc);
		REQUIRE(c.setup());
	}
	SECTION("Test Compass init false")
	{
		MockCompass mc(false, 1);
		Compass c(mc);
		REQUIRE(!c.setup());
	}
	SECTION("Test MockCompass mode static")
	{
		MockCompass mc1(true, 1);
		bool result = true;
		int still = mc1.getHeading();
		for(int var = 0; var < 100; ++var) {
			if (still != mc1.getHeading()){
				result = false;
			}
		}
		REQUIRE(result);
	}
	SECTION("Test MockCompass modes shifting")
	{
		MockCompass mc2(true, 2);
		mc2.setHeading(160);
		bool result = true;
		int old = mc2.getHeading();
		int next;
		for (int var = 0; var < 150; ++var) {
			next = mc2.getHeading();
			if (		next != old
					|| 	next != old+1
					|| 	next != old-1)	{
				// success
			}
			else {
				result = false;
			}
			old = next;
		}
		REQUIRE(result);
	}
	SECTION("Test MockCompass modes rotating")
	{
		MockCompass mc3(true, 3);
		mc3.setHeading(100);
		bool result = true;
		int old = mc3.getHeading();
		int next;
		for (int var = 0; var < 150; ++var) {
			next = mc3.getHeading();
			if (next-1 != old)	{
				result = false;
			}
			old = next;
		}
		REQUIRE(result);
	}
	SECTION("Test that compass always returns a grade between 0 and 360")
	{
		MockCompass mc(true, 2);
		Compass c(mc);
		int heading = 0;
		bool result = true;
		for (int var = 0; var < 10000; ++var) {
			heading = c.getHeading();
			if (heading < 0 || heading > 360){
				result = false;
			}
		}
		REQUIRE(result);
	}
}
