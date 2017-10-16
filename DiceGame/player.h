#pragma once
#include <stdbool.h>

/**
* \brief if player has 25000 or more points then they won
* \return true if won.
*/
bool hasWon(void);

/**
* \brief sets points_total = 0.
*/
void startGame(void);

/**
*  \brief throws the bonus throw for the 4th of a kind.
*  \param int dice_kind is the number is eyes the player is throwing for, 
*  \param char* dice is the dice thrown by the player
*/
void challengeThrow(int dice_kind, char* dice);

/**
* \brief The amount of throws and and points for the turn to should start at 0.
*/
void startTurn(void);

/**
* \brief Throw dice and add the results to the points for the turn.
* \param char* dice is a string of the dice that the player threw. as such this is meant to indicate the result of the dice throw and it
*/
void throwDice(char* dice);

/**
* \brief This will return the points for the turn and end the turn.
* \return points of the turn
*/
int stopTurn(void);

/**
* \brief This will return the total score for the player that has accumulated throughout each turn.
* \return the total score of the player
*/
int getTotalScore(void);
