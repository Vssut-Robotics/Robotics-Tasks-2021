import random
from collections import Counter
n=int(input("Enter the no. of overs: "))
over=1
ball=1 
coin=["heads", "tails"]
toss=random.choice(coin)
s=input("heads or tails: ") # s is user's selection for heads or tails
print("the coin landed on " + toss)
pick=["bat", "bowl"]
player_pick=""
comp_pick=""
player_hit=""
comp_hit="" 
if s == toss:
  player_pick=input("choose to bat or bowl : " )# choose to bat or bowl and type bat or bowl
    if player_pick=="bat":
     print("comp will bowl")
    elif player_pick=="bowl": 
      print("comp will bat")
  else: 
        comp_pick=random.choice(pick) 
        print("comp won the toss and chose to " + comp_pick) 
      if comp_pick=="bat":
          print("you will bowl") 
      elif comp_pick=="bowl":
            print("you will bat") 
    innings=1
    runs=0
    target=1 
    while over<n :
      print("innings " +str(innings))
      print("over",over,"ball",ball)
      player_hit=int(input("Enter your number (1 to 6): "))
      comp_hit=random.randint(1,6) 
      print("computer got: ", comp_hit,"\n")
      ball=ball+1
      if(player_hit==comp_hit):
        if ((player_pick=="bat" or comp_pick=="bowl") and innings==1):
          print("you are out")
          innings=2 
          print("now you will bowl to defend: " + str(target))
        elif((player_pick=="bowl" or comp_pick=="bat")and innings==1): 
          print("comp is out") innings=2 
          print("now you will bat to get: " +str(target)) 
        elif((player_pick=="bat" or comp_pick=="bowl") and innings==2):
          print("out. Comp wins.")
          break
        elif((player_pick=="bowl" or comp_pick=="bat") and innings==2): 
          print("out. YOU WIN.")
          break
        else: 
          if((player_pick=="bat" or comp_pick=="bowl") and innings==1):
            runs = runs + player_hit 
            print("score is: " + str(runs))
            elif((player_pick=="bat" or comp_pick=="bowl") and innings==2):
              if(target-player_hit>0): 
                target= target-player_hit 
                print("to get : " + str(target)) 
               else: print("you win!!") 
                  break
               elif((player_pick=="bowl" or comp_pick=="bat") and innings==1):
                    target = target+comp_hit
                    print("target is: " +str(target))
               elif((player_pick=="bowl" or comp_pick=="bat") and innings==2):
                    if(runs-comp_hit>0):
                        runs=runs -comp_hit 
                        print("to defend: " +str(runs))
                    else:
                        print("you lost!") 
                        break
