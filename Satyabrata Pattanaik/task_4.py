def specialNumber(n):
 
    # Checking whether entered
    # number is 2 digit or not
    if (n < 10 or n > 99):
        print("Invalid Input! Number",
              " should have 2 digits only")
    else:
     
        # Finding the first digit
        first = n // 10
         
        # Finding the last digit
        last = n % 10
         
        # Finding the sum
        # of the digits
        sum = first + last
         
        # Finding the product
        # of the digits
        pro = first * last
         
        if ((sum + pro) == n):
         
            print(n ," is a Special ",
                   "Two-Digit Number")
        else:
         
            print(n , " is Not a ",
                "Special Two-Digit Number")
         
# Driver code
n = 59
specialNumber(n)