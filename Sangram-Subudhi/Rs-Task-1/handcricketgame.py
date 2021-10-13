import random
import math
Overs = int(input("Enter number of Overs ")) #input the number of overs
Computer_score = random.randint (0,Overs*36) #Computer's score should not exceed more than 36
#print("Computer has score = ", end="")
print(f"Computer has score {Computer_score}")
print(f"Your target {Computer_score+1}")

m=0
OriginalScore=0

def sum(m): #for calculating the number of score
    m=compscore 
    return m
for overs in range(1,Overs+1): #taking for loop for overs 
    for balls in range(1,7): #for loop for number of balls
        compscore=int(input("Enter number to bat="))
        print("Computer's turn= ",end="")
        Computer_No = random.randint(0,6) #Computer's turn to bat
        print(Computer_No)
        if Computer_No == compscore:
            print("out")
            break
        else:
            OriginalScore+=sum(m)# calculating the number of score of the player
        if OriginalScore > Computer_score:
            break

if OriginalScore>Computer_score:
    print("You won the game by", OriginalScore-Computer_score-1,"runs") #how many runs player won the match
elif OriginalScore == Computer_score:
    print("Match Draw")
else:
    print("Computer won the match by",Computer_score-OriginalScore-1,"runs") #how many runs computer won the match