import random as rand
def play(ovs):
    total_balls=ovs*6
    m=1
    run=0
    score=rand.randint(0,ovs*36)                                                 #random score generator                                                     
    target=score+1                                                               #target for user
    print("Computer has scored",score,"runs. Your target is",target,"runs.")
    while (run<score) and (m<=total_balls):
        comp_run=rand.randint(0,6)
        play_run=int(input("Enter the run between 1 to 6 :"))
        if (play_run==comp_run):
            print("You are OUT!!!")
            break
        else:
            run+=play_run
            print("Score ::",run)
        m+=1
    if (run>=target):
        print("Your score is,",run,"\n")
        print("Congrats , you won the match .")
    elif (run==score):
        print("This is DRAW .")
    else:
        print("Oh NO!! You lost the match .  ")
        
        
a=int(input("Enter the overs ::"))                                             #main function call
play(a)