#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness_c.h>

extern "C" {
	#include "player.h"
};

TEST_GROUP(TEST_PLAYER)
{
	void setup()
	{
		startGame();
	}

	void teardown()
	{

	}
};

TEST(TEST_PLAYER, TotalScoreMustStartAtZero)
{
	CHECK_EQUAL_C_REAL(0.0, getTotalScore(), 0.00001);
}

