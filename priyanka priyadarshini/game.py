import random
list=["emotica","vibranz","souls","avc","pixels"] #it represents th list of clubs
word=random.choice(list) #the computer randomly choices one of the above given list of clubs

letter=[]
letter.extend(word) #here we have taken letter as a list which has the same no. of elements as that of chosen word
n=len(letter) #the length of the letter list is calculated
count=0

for i in range(n):
    letter[i]="*"
print("the game is about to start.......please wait....")
print(letter) # now we give the encrypted word with the hint
if word=="vibranz":
    print("hint:makes music alive")
elif word=="emotica":
    print("hint:performs theatricals")
elif word=="souls":
    print("hint:speaks through music")
elif word=="avc":
    print("hint:where writings are turned into cinema")
else:
    print("hint:freezes memories for us")
score=10
print("how will you guess:") #we ask the user how he will guess
print("1.entire word")
print("2.letter by letter")
option=int(input("option:")) #one out of the given option is chosen by the user

if option==1:
    while score>0:
        guess=input("guess:")
        if guess==word:
            print("you won!!") #if the user guesses the right word he wins and the scoore is increased by 5 points
            score=score+5
            print("score:",score)
            break
        else:
            print("you lose!!") #if the user guesses the wrong word he loses by 3 points
            score=score-3
            print("score:",score)
else:
    while score>0:
        guess=input("guess:")
        if guess in word:
            if guess not in letter:
                for i in range(n):  #if the guessed letter is correct then it is placed in the right place of the list letter
                     if word[i]==guess:
                         letter[i]=guess
                         count=count+1
                print(letter)
                score=score+3
                print("correct guess")
                print("score:",score)
                            
                
            else:
                print("already received ") #avoid repetition
                print("score:",score)
            
               
                
        else:
            print("incoreect guess") #incorrect guess leads to lose in score by 2
            score=score-2
            print("score:",score)
        if count==n:
            break
        

    
    if score>0: 
        print("you win")
    else:
        print("you lose\nclub name is:",word)
            

