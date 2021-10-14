import random

user_score = 0
c_no_over = int(input("Enter the number of overs: "))
comp_score = c_no_over * random.randint(0, 36)
print("computer score is:",comp_score)
print("your target is:",comp_score+1)
u_no_over=0
u_pred=0
i=1
while i <= c_no_over :
    c=1
    while c <= 6 :
        u_no_over = random.randint(0, 6)
        u_pred=int(input("enter a to bat between 0-6  : "))
        print("computer's number is",u_no_over)
        if u_no_over == u_pred :
            break
        else:
            user_score=user_score+u_pred
        print("over ", i ,"ball", c )
        print("Total runs",user_score)
        c+=1
    if u_no_over == u_pred:
        break

    i+=1
print("computer score is : ",comp_score)
print("Your score is : ",user_score)
if comp_score > user_score :
    print("computer wins by",comp_score - user_score,"runs")
else:
    print("user wins by",user_score - comp_score,"runs")
