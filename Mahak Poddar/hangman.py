import random
score=10
guess=''
gussed=''
display=[]
repeat=0
store=[]
count=0
list=["lagan","highway","thor","dangal","newton"]
word=random.choice(list)
print(word)
n=len(word)
display.extend(word)
for i in range(n):
    display[i]="*"
print("let's begin the game")
print
print(display)
while score>0:
    print("guess your letter")
    guess=input()
    gussed=guess
    for i in range(n):
        if word[i]==guess:
            display[i]=guess
            score+=3
            count+=1
            print(display)
    if guess not in word:
        print("wrong answer")
        score-=2
        print(score)
    if count==n:
         break    
for i in range(n):
    if display[i]==word[i]:
        print("won",score)
        break
    else:
        print("loose")
        break
    
