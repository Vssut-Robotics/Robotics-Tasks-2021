import random

def num_of_overs(overs):
    n = overs * 36
    com_score = random.randint(0, 36)
    return com_score
   
   
def user():
    user_num = int(input("Enter a number between 1 to 6 to bat : "))
    com_num = random.randint(0,6)
    print("Computer's number", com_num)
    return user_num, com_num

   
def result(user_num, com_num, total, comp_score):
    if(user_num == com_num):
        print(" Total runs scored", total)
        winning_margin = comp_score - total
        print("You are Out. Computer Won the game by", winning_margin, "runs")
        return 0
    else:
        total = total + user_num
        print(" Total user's score", total)
        if(total > comp_score):
            winning_margin = total - comp_score
            print("You won the game by", winning_margin, "runs")
            return 0
        else:
            return total
       
### Main Function        
   
total = 0    
overs = int(input("Enter number of overs :"))
comp_score = num_of_overs(overs)
print("Computer has scored", comp_score,"runs. Your Target is", comp_score + 1)

for i in range(overs):
    for j in range(6):
        print("Over", i+1, "Ball", j+1)
        user_num, com_num = user()
        total = result(user_num, com_num, total, comp_score)
        if total == 0:
            break

if (total != 0):      # total will  be zero if match ended before the overs are completed.
    if(total == comp_score):
        print(" Match tied")
    else:
        winning_margin = comp_score - total
        print("Overs completed. Computer won the game by", winning_margin, "runs")
