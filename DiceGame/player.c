#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "player.h"

#define BUFFER_LENGTH 14
#define DICE_SIDES 6
#define WINNING_SCORE 25000

static int points_turn;
static int points_total;
static int last_throw[DICE_SIDES];
static int throws_turn;

void startGame(void)
{
	points_total = 0;
}

void startTurn(void)
{
	points_turn = 0;
	throws_turn = 0;
}

int getTotalScore(void)
{
	return points_total;
}

static void countDieKind(char* dice, int* eyes)
{
	char buffer[BUFFER_LENGTH];
	strncpy(buffer, dice, BUFFER_LENGTH - 1);
	char* s = ",";
	char *token;

	/* get the first token */
	token = strtok(buffer, s);

	while (token != NULL)
	{
		int die = (int)strtol(token, NULL, 10);
		switch (die)
		{
		case 1:
			eyes[0]++;
			break;
		case 2:
			eyes[1]++;
			break;
		case 3:
			eyes[2]++;
			break;
		case 4:
			eyes[3]++;
			break;
		case 5:
			eyes[4]++;
			break;
		case 6:
			eyes[5]++;
			break;
		default:
			break;
		}
		token = strtok(NULL, s);
	}
}

static int calcPointForDie(int* eyes)
{
	int points = 0;
	int mod_one_of_a_kind[] = { 100, 0, 0, 0, 50, 0 };
	int mod_three_of_a_kind[] = { 1000, 200, 300, 400, 500, 600 };
	for (int i = 0; i < DICE_SIDES; i++)
	{
		switch (eyes[i])
		{
		case 1:
		case 2:
			points += mod_one_of_a_kind[i] * eyes[i];
			break;
		case 3:
			points += mod_three_of_a_kind[i];
			break;
		case 4:
			points += mod_three_of_a_kind[i] * 10;
			break;
		case 5:
			points += mod_three_of_a_kind[i] * 10;
			points += mod_one_of_a_kind[i];
			break;
		case 6:
			points += mod_three_of_a_kind[i] * 10;
			points += mod_one_of_a_kind[i] * 2;
			break;
		case 7:
			points += mod_three_of_a_kind[i];
			points += mod_three_of_a_kind[i] * 10;
			break;
		default:
			break;
		}
	}
	return points;
}

static void saveThrow(int* eyes)
{
	for (int i = 0; i < DICE_SIDES; i++)
	{
		last_throw[i] = eyes[i];
	}
}

static void annulatePoints(void)
{
	points_turn = 0;
}

void throwDice(char* dice)
{
	int eyes[DICE_SIDES] = { 0,0,0,0,0,0 }; //ones is eyes[0] and six is eyes[5]
	countDieKind(dice, eyes);
	int points = calcPointForDie(eyes);

	if (points == 0)
	{
		points_turn = 0;
	}
	else
	{
		points_turn += points;
	}
	saveThrow(eyes);
	throws_turn++;
}

void challengeThrow(int die_kind, char* dice)
{
	if (throws_turn == 1 && last_throw[die_kind - 1] == 3)
	{
		throws_turn++;
		annulatePoints();

		int eyes[DICE_SIDES] = { 0,0,0,0,0,0 }; //ones is eyes[0] and six is eyes[5]
		countDieKind(dice, eyes);

		if (eyes[die_kind - 1] == 0)
		{
			points_turn = -500;
		}
		else
		{
			eyes[die_kind - 1] += last_throw[die_kind - 1];
			points_turn += calcPointForDie(eyes);
		}
	}
}


int stopTurn(void)
{
	points_total += points_turn;
	return points_turn;
}

bool hasWon(void)
{
	return points_total >= WINNING_SCORE;
}