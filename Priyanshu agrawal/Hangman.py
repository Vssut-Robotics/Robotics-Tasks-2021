import random #to call the random function
score = 10  #initial  score given to the player
c=0
d=0
guesses=""
ans=[]
gues=''
print('HELLO')
print(':: WELCOME TO THE HANGMAN GAME ::')
print('::DEVELOPED BY SWAGAT SUMAN MISHRA::')
names=['apne','uri','toilet','chapaak','gadar','border','kahaani','vaastav','damini','chhichhore']      #sample movies names
word = random.choice(names)
n=len(word)             # to count the no. of letter in the film
ans.extend(word)        # to store the film name in another variable
for i in range(n):      # loop to display * 
    ans[i]='*'

print(ans)
while score>0:
     print('guess the letter')
     guess=input()                      # to input the guesses from the user
     if guess in word :                 #to check the input given by the user is present in the word or not
             for i in range(n):
                 if word[i]==guess:
                   ans[i]=guess
                   c+=1
             print(ans)
             score+=3                   #to assign +3 score to every correct input
     if guess not in word:
         print('wrong answer')          #if the input given by the user is not present in the word
         score-=2
         print(score)
     if c==n:
         break                          # counter variable to exit the loop 


for i in range(n):                      #to display whether the user wins or loose
     if ans[i]==word[i]:
          print('won',score)
          break
     else:
          print('looser')

     
