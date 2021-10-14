import random

lst1= [1,2,3,4,5,6,7,8,9,10]

chances_1= 20
no_of_chances_1= 0
your_runs= 0
 
print ("-----------------------------------------------\nYour Batting\n")
while no_of_chances_1 < chances_1:
    
    runs= int(input("Enter Runs for Your Batting Turn: "))
    comp_bowl= random.choice(lst1)

    if runs==comp_bowl:
        print ("Your Guess: ",runs,",Computer Guess: ",comp_bowl)
        print ("You are Out. Your Total Runs= ", your_runs,"\n")
        break
    elif runs>10:
        print ("ALERT!! Support No only till 10\n")
        continue
    else:
        your_runs= your_runs+runs
        print ("Your Guess: ",runs,",Computer Guess: ",comp_bowl)
        print ("Your runs Now are: ",your_runs,"\n")

    no_of_chances_1= no_of_chances_1 + 1  

lst2= [1,2,3,4,5,6,7,8,9,10]

chances_2= 20
no_of_chances_2= 0
comp_runs= 0
print ("-----------------------------------------------")
print ("Computer Batting-\n")
while no_of_chances_2 < chances_2:

    bowl= int(input("Enter Runs for Your Bowling Turn: "))
    comp_bat= random.choice(lst2)

    if comp_bat==bowl:
        print ("Computer Guess: ",comp_bat,"Your Guess: ",bowl)
        print ("The Computer is Out. Computer Runs= ",comp_runs,"\n")
        break
    else:
        comp_runs= comp_runs+comp_bat
        print ("Computer Guess: ",comp_bat,"Your Guess: ",bowl)
        print ("Computer Runs: ",comp_runs,"\n")

        if comp_runs > your_runs:
            break
        
    no_of_chances_2= no_of_chances_2+1


print ("\n-----------------------------------------------\nRESULTS: ")

if comp_runs < your_runs:
    print ("\nYou won the Game.\n\nYour Total Runs= ",your_runs,"  [Bowls taken(Out of 20): ",no_of_chances_1+1,"]","\nComputer Total Runs= ",comp_runs,"  [Bowls Taken(Out of 20): ",no_of_chances_2+1,"]\n")

elif comp_runs == your_runs:
    print ("The Game is a Tie")

else:
    print ("\nComputer won the Game.\n\nComputer Total Runs= ",comp_runs,"  [Bowls Taken(Out of 20): ",no_of_chances_2+1,"]","\nYour Total Runs= ",your_runs,"  [Bowls taken(Out of 20): ",no_of_chances_1+1,"]\n")
