def A():
     
     w=int(input("Enter the size of array:"))
     print("Enter the elements:",end='')
     lt=list(map(int,input().split())) #To create a list of elements provided by the user
     print("OUTPUT:",end='')
     
     for i in range(w):
         c=1                            #Initial counter
         for j in range(i,w-1):
             prod= lt[j] * lt[j+1]      #If the product is negative i.e. (val<0) then the number and it's adjacent number must have opposite signs 
             if prod <0:
                 c+=1

             else:
                 break

             
         print(c,"",end='')
     print("\n")


def B():
    
    l=[]    #List of movies denoting the length
    r=[]    #List of movies denoting the rating
    moviel=[] #List of the respective movies having the values of l*r
    n=int(input("Enter number of movies:")) 
    for i in range (n):

        a=i+1 
        print("L",a,":",end='')
        l.append(int(input()))
        print("R",a,":",end='')
        r.append(int(input()))
        data= l[i]*r[i]
        moviel.append(data)

    pos=0                                   
    maxrate = max(r)                        #To find the movie with maximum ratings
    prefer_movie = max(moviel)              #To find the movie with maximum l*r value
    for k in range(len(moviel)):
        if(moviel[k] == prefer_movie):      #Finds the movie that has equal value as the maximum one
            if(r[k] == maxrate):            #Finds the movie that has equal ratings as the maximum one
                pos=k+1                     #Denotes the positon of the movie
                break

     
    if(pos ==1):
        print(pos,'ST MOVIE')

    elif(pos ==2):
        print(pos,'ND MOVIE')

    elif(pos==3):
        print(pos,'RD MOVIE')

    else:
        print(pos,'TH MOVIE')

    print('\n')

        

def C():
    
    m=int(input("Enter size of array:"))
    print("Enter the elements:",end='')
    lst=list(map(int,input().split())) #To create list of elements

    if m == len(lst):   #Checks whether the length of the list and the size provided by user is same or not 
        cost=0
        lst.sort()      #Sorts the list in ascending order 
       
        for j in range(m+1):
            q=0
            if m > 1:
                cost+=lst[q]
                x=lst[q+1]      #Stores the value of element to be removed
                lst.remove(x)   #Removes the adjacent element
                m-=1            #Reduces the size of array
        j+=1
            
        print("OUTPUT:",cost)





A()
B()
C()
