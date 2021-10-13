# Robotics_Learning_series_2
## Hand Cricket Game
Base Rules of the game(2 Player Game) :-
> 1. One player writes down a random number between 0-6.
> 2. The other player tries to guess the same number as that of the other
   > player.
> 3. If both the number matches then the player who is on bat gets out.
> 4. Else the player who is on bat scores the run which he chooses at
   >each turn until they both have a match of the same number.
> 5. The player who scores more runs wins the game in a limited number
    > of tries.
    
## Task - Design the above game in python with the following specifications :

Assume Program to be Player 2
1. The program should asks the user for number of overs in the game
2. The program generates a random score ranging between [ 0 to
Number of overs * 36 ] . This is the score for the computer. The user
must reach this goal.
3. The program now generates a random number between 0 and 6 for
each turn
4. Then it takes input from the user. Based on input
     a. If the number matches, the player is declared out
     b. Else the runs scored gets added to the scorecard
5. The game goes on until -
      a. The number of overs are completed
      b. The batting player gets out
      c. The players scores more than computer
6. At the end of the game, the program should display which
team(Computer/ User) won the game by how many runs.

# Notes:
> 1. Program must be fully function based.
> 2. Code should not be plagiarized.
> 3. Input must be between 1& 6 for the player when he/she bats


# Example Program Run
-------------------

Enter number of overs : 1 (Player input)
Computer has scored 13 runs. Your target 14 runs

Over 1 Ball 1
Enter number to bat : 3 (Player input)
Computer’s number : 5
Total Runs : 3

Over 1 Ball 2
Enter number to bat : 4 (Player input)
Computer’s number : 1
Total Runs : 7

Over 1 Ball 3
Enter number to bat : 3 (Player input)
Computer’s number : 3
Total Runs : 7

You are Out

Computer Won the gam
