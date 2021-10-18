import random         #TO USE THE RANDOM FUNTION OF LIBRARY.
listofguess=['lagaan','highway','thor','dangal','newton']

    
random.shuffle(listofguess)       #TO SELECT A RANDOM OF THE LIST.
selected=list(listofguess[3])     #TO SELECT THE 4TH ELEMENT FROM THE LIST FROM THE SHUFFLED LIST,HERE WE CAN TAKE ANY ELEMENT AS AN INPUT NO ISSUES.
new_list=[]     #HERE IS A NEW LIST TO STORE THE LETTERS OF A RANDOM DELECTED MOVIE.
new_list.extend(selected)       #HERE EACH LETTERS OF THE SELECTED WORD IS CONVERTED TO THE ELEMENTS OF THE NEW_LIST.
score=10        #SO AS TO USE IT AS STARTING SCORE.
length=len(new_list)
length1=len(selected)
#NOW IT'S THE TIME FOR LOOPING.
for i in range(length):
    new_list[i]='*'
print('  '.join(new_list))       #HERE THE SAME NO. OF STARS ARE DISPLAYED AS THE NO. OFCHARATERS IN THE SELECTED MOVIE.
print("score:{}".format(score))

for j in range(15):         #TO TAKE INPUT FROM USER.
    
    guess=input('guess a letter:')
    guess=guess.lower()             #SECURITY
    print()
    if(guess==''or guess==' '):
        print('no character recieved')
        continue

        
    if(guess in listofguess[3]):
        
        print('correct guess')
        score=score+3
        for k in range(length1):        #IT WILL ITERATE THE NO. OF TIMES THE LENGTH OF THE SLECTED MOVIE TO CHECK ITS LETTER.
        
            if selected[k]==guess:
                if new_list[k]!=guess:
                    new_list[k]=guess       #OVERLAPPING 
                else:
                    print('already received character')
                    score=score-5
                    break
    else:
        print('incorrect guess')
        score=score-2                
                
    
        
    print('  '.join(new_list))      #HERE AFTER THE ENTRY THR MOVIE NAME WILL BE PRINTED
    print("score:{}".format(score))
    if score<=0:
        break
    elif new_list==selected:
        break
if new_list==selected:
    print('you win')
else:
    print('you lose')
