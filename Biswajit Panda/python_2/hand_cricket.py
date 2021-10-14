from random import*


def game_score(balls, target):
    score = 0
    while balls > 0 and score < target:
        rnum = randint(0, 6)
        run = int(input("Enter your run between 1 and 6 : "))

        if 1 <= run <= 6:
            if rnum == run:
                print("You are out")
                break
            else:
                score += run
        else:
            print("Enter valid run between 1 and 6")
            continue
        balls -= 1
    return score


def winner(ch):
    while ch == 1:
        overs = int(input("Enter the number of overs in the game : "))
        target = randint(0, overs*36)
        balls = overs*6

        score = game_score(balls, target)

        win = score-target

        if score >= target:
            print("The user won the game by {} runs.".format(win))
        else:
            print("The computer won the game by {} runs.".format(-win))

        ch = int(input("Do you want to play again?"))


winner(int(input("Do you want to play the Hand Cricket Game?\n1 - Yes\n0 - No\n")))
