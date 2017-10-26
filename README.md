# DiceGame

![Class diagram](https://raw.githubusercontent.com/sirasmu/DiceGame/master/TDD.PNG)

Each game starts with calling startGame() to ensure the total points for the player starts at 0. At the start of a turn call startTurn() to set the points and throws of that turn to 0.  Call throwDice() for each throw with the die kinds the player wants to save, separated by comma. The function stopTurn() returns the score for the turn.  When calling hasWon() it returns true if the player has reached 25000 total points or more. The function getTotalScore() returns the total score.  The helpingfunction countDieKind() takes 2 variables, the string dice, and int array eyes, and counts up each eye in the string.  The helping function calcPointForDie() takes an int array and returns the points. This is will be needed when calculating points dice thrown. The function saveThrow() takes an int array and saves the dice thrown last turn, used for the next turn. The function challengeThrow() takes 2 variables, an int and a string. The int is dieKind and is the number the player is throwing for, and the string is the list of dice thrown. Returns the points for that throw. 

## Test list 

Total score must start at 0 
 
One die of one should give 100 
 
One die of five should give 50 
 
One die of two, three, four or six should give 0 
 
Two dice of one should give 200 
 
Three dice of twos, fours, fives, sixes should give their eye count times 100 
 
Four dice of twos, fours, fives, sixes should give their eye count times 1000 
 
three dice of ones should give 1000 
 
Four dice of ones should give 10000 
 
When a turn starts the players points for that turn must be 0 
 
If a throw does not result in any point the points for that turn must be 0 
 
A player can only throw a challenge throw if the player got three of a kind on their first turn 
 
If player reached 25000 or more they win 
 
if challenge throw is won, the player should get 4 of a kind points for the matching eye 
 
if challenge throw is cancelled, player should get points for his current throw 
 
If the challenge is lost the player will get -500 points for that turn 
 
A challenge throw can only be called once per player turn (We decided that the challenge throw only works once as that makes the most sense when a player physically throws dice, since they must remove the four dice they wish to rethrow) 
 
A challenge throw also counts additional points from any point giving dice on that throw 
 
A player should maximally be able to throw seven dice 
 
Challenge throws can only be thrown when the previous dice throw had three of a kind of want to try to get four of a kind for 

## TDD reflection

My experience with Test Driven Development was great. The design of the code was based on making it able to pass one test at a time and by so it became much more manageable to implement the code without designing a bloated system, since I will only implement code when I have designed a test that the code should be able to pass. This ensures that I have control over whether the code lives up the expectations I set for its features. By testing it iteratively it be checked whether I get the expected result . This removes the fear of making a mistake when refactoring the code. 
