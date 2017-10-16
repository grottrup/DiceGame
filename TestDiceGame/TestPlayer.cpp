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

TEST(TEST_PLAYER, DiceThrowOfOne)
{
	startTurn();
	throwDice("1");
	CHECK_EQUAL_C_INT(100, stopTurn());
}

TEST(TEST_PLAYER, DiceThrowOfTwo)
{
	startTurn();
	throwDice("2");
	CHECK_EQUAL_C_INT(0, stopTurn());
}

TEST(TEST_PLAYER, DiceThrowOfFive)
{
	startTurn();
	throwDice("5");
	CHECK_EQUAL_C_INT(50, stopTurn());
}

TEST(TEST_PLAYER, DiceThrowOfTwoOnes)
{
	startTurn();
	throwDice("1,1");
	CHECK_EQUAL_C_INT(200, stopTurn());
}


TEST(TEST_PLAYER, DiceThrowOfThreeOfTwos)
{
	startTurn();
	throwDice("2,2,2");
	CHECK_EQUAL_C_INT(200, stopTurn());
}

TEST(TEST_PLAYER, DiceThrowOfThreeOfSixs)
{
	startTurn();
	throwDice("6,6,6");
	CHECK_EQUAL_C_INT(600, stopTurn());
}

TEST(TEST_PLAYER, DiceThrowOfThreeOfOnes)
{
	startTurn();
	throwDice("1,1,1");
	CHECK_EQUAL_C_INT(1000, stopTurn());
}

TEST(TEST_PLAYER, DiceThrowOfFourOfTwos)
{
	startTurn();
	throwDice("2,2,2,2");
	CHECK_EQUAL_C_INT(2000, stopTurn());
}

TEST(TEST_PLAYER, DiceThrowOfFourOfSixs)
{
	startTurn();
	throwDice("6,6,6,6");
	CHECK_EQUAL_C_INT(6000, stopTurn());
}

TEST(TEST_PLAYER, DiceThrowOfFourOfOnes)
{
	startTurn();
	throwDice("1,1,1,1");
	CHECK_EQUAL_C_INT(10000, stopTurn());
}

TEST(TEST_PLAYER, DiceThrowCombi1)
{
	startTurn();
	throwDice("1,1,1,5");
	CHECK_EQUAL_C_INT(1050, stopTurn());
}

TEST(TEST_PLAYER, DiceThrowCombi2)
{
	startTurn();
	throwDice("1,1,2,4,4,4");
	CHECK_EQUAL_C_INT(600, stopTurn());
}


TEST(TEST_PLAYER, StartTurnWithZeroPoints)
{
	startTurn();
	throwDice("1");
	stopTurn();
	startTurn();
	CHECK_EQUAL_C_INT(0, stopTurn());
}

TEST(TEST_PLAYER, GetTotalScoreForAllTurns)
{
	startTurn();
	throwDice("1");
	throwDice("1");
	throwDice("1");
	throwDice("1");
	stopTurn();
	startTurn();
	throwDice("1");
	stopTurn();
	CHECK_EQUAL_C_INT(500, getTotalScore());
}

TEST(TEST_PLAYER, PointsForSevenOfAKind)
{
	startTurn();
	throwDice("2,2,2,2,2,2,2");

	CHECK_EQUAL_C_INT(2200, stopTurn());
}

TEST(TEST_PLAYER, PointsForSevenOfAKind2)
{
	startTurn();
	throwDice("1,1,1,1,1,1,1");

	CHECK_EQUAL_C_INT(11000, stopTurn());
}

TEST(TEST_PLAYER, PointsForSevenOfAKind3)
{
	startTurn();
	throwDice("5,5,5,5,5,5,5");

	CHECK_EQUAL_C_INT(5500, stopTurn());
}

TEST(TEST_PLAYER, PointsForSixOfAKind)
{
	startTurn();
	throwDice("1,1,1,1,1,1");

	CHECK_EQUAL_C_INT(10200, stopTurn());
}

TEST(TEST_PLAYER, PointsForSixOfAKind2)
{
	startTurn();
	throwDice("5,5,5,5,5,5");

	CHECK_EQUAL_C_INT(5100, stopTurn());
}

TEST(TEST_PLAYER, PointsForFiveOfAKind)
{
	startTurn();
	throwDice("1,1,1,1,1");

	CHECK_EQUAL_C_INT(10100, stopTurn());
}

TEST(TEST_PLAYER, ChallengeThrow)
{
	startTurn();
	throwDice("5,5,5");
	challengeThrow(5, "1,1,1,1");
	CHECK_EQUAL_C_INT(-500, stopTurn());
}

TEST(TEST_PLAYER, ChallengeThrow2)
{
	startTurn();
	throwDice("5,5,5");
	challengeThrow(5, "5");
	CHECK_EQUAL_C_INT(5000, stopTurn());
}

TEST(TEST_PLAYER, NoPointsForTurnOnZeroPointThrow)
{
	startTurn();
	throwDice("1");
	throwDice("1");
	throwDice("1");
	throwDice("1");
	throwDice("2");
	CHECK_EQUAL_C_INT(0, stopTurn());
}

TEST(TEST_PLAYER, CancelledChallengeThrow)
{
	startTurn();
	throwDice("2,2,2,3,3,3");
	CHECK_EQUAL_C_INT(500, stopTurn());
}

TEST(TEST_PLAYER, ChallengeThrowWorksOnce)
{
	startTurn();
	throwDice("2,2,2,3,3,3,6");
	challengeThrow(2, "2,4,6,6");
	challengeThrow(3, "3,4,5,6");
	CHECK_EQUAL_C_INT(2000, stopTurn());
}

//not tested in compiler
TEST(TEST_PLAYER, WinsWhen25000ReachedPoints)
{
	startTurn();
	throwDice("1,1,1,1");
	throwDice("1,1,1,1");
	throwDice("1,1,1,1");
	stopTurn();
	CHECK_EQUAL_C_BOOL(true, hasWon());
}

//not tested in compiler
TEST(TEST_PLAYER, WinsWhen25000ReachedPoints2)
{
	startTurn();
	throwDice("1,1,1,1");
	throwDice("1,1,1,1");
	throwDice("5,5,5,5");
	stopTurn();
	CHECK_EQUAL_C_BOOL(true, hasWon());
}

TEST(TEST_PLAYER, WinsWhen25000ReachedPoints3)
{
	startTurn();
	throwDice("1,1,1,1");
	throwDice("1,1,1,1");
	throwDice("5,5,5");
	stopTurn();
	CHECK_EQUAL_C_BOOL(false, hasWon());
}


TEST(TEST_PLAYER, ChallengeThrowAlsoCountsAdditionalPoints)
{
	startTurn();
	throwDice("2,2,2");
	challengeThrow(2, "2,1");
	CHECK_EQUAL_C_INT(2100, stopTurn());
}

TEST(TEST_PLAYER, MaxSevenDiceThrown)
{
	startTurn();
	throwDice("1,2,3,4,5,6,6,6"); //addional dice thrown will not be counted
	CHECK_EQUAL_C_INT(150, stopTurn());
}

TEST(TEST_PLAYER, ChallengeThrowsValidWhenDiceThrowHadThreeOfAKind)
{
	startTurn();
	throwDice("2");
	challengeThrow(2, "2,2,2");
	CHECK_EQUAL_C_INT(0, stopTurn());
}


