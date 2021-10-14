import random
moviename = ['lagaan','highway','thor','dangal','newton']
#function will choose one random word from the given list
moviename = random.choice(moviename)

print("Guess the movie")

guesses = ''
#initial score of the user
score = 10

while score > 0:

     #counts the number of times the letter does not match 
     c=0
     for char in moviename:

        if char in guesses:
            print(char,end="")
        

        else:
         print('*',end="")
         c+=1

     if c >=1:
        print("")  
        print("Your Score:",score)

     if c ==0:
        print("")
        print("Your Score:",score)
        print("YOU WIN!!")
        break

     #user has to input new alphabet if the previous alphabet did not match
     guess=input("Guess a letter:")
     #new input will be stored in guesses
     guesses += guess

     if guess not in moviename:
        score-=2
        print("Wrong guess!Try again.")

        if(score <= 0):
         print("YOU LOOSE!")

     else:
            print("Correct Guess")
            score+=3
        

   
