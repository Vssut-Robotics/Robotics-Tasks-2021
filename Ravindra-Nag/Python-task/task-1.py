import random

def generate():
    """generates a random 4-digit number

    Returns:
        int: random 4-digit number
    """
    num = 0
    for i in range(4):
        num = num*10 + random.randint(1,9);
    return num

def convert_to_list(num):
    """ Converts str to list conaining each character

    Args:
        num (str): string entered by user

    Returns:
        list: list of characters in string
    """
    ans = list(x for x in num)
    return ans

def check_position(guess, target, correct):
    """ Checks for digits in correct place

    Args:
        guess (list): guess list
        target (list): target list
        correct (list): list containing correct digits

    Returns:
        list: list containing two values- number of digits in right and wrong places
    """
    right = 0
    wrong = 0
    for i in range(len(correct)):
        if guess.index(str(correct[i])) == target.index(str(correct[i])):
            right +=1
        else:
            wrong += 1
    return [right, wrong]

def get_correct_list(guess, target):
    """ Compares guess with target

    Args:
        guess (list): guess list
        target (list): target list

    Returns:
        list: digits guessed correctly
    """
    correct = []
    for i in range(4):
        if target[i] in guess:
            correct.append(target[i])
            guess.remove(target[i]) 
    return correct          

def get_unique_guesses(correct,already_guessed):
    """ Compares correct list with already_guessed list

    Args:
        correct (list): list of correctly guessed digits
        already_guessed (list): list of already guessed digits

    Returns:
        int: number of unique guesses
    """
    count = 0
    for i in range(len(correct)):
        if correct[i] in already_guessed:
            already_guessed.remove(correct[i])
        else:
            count += 1
    return count         

def score_update(score, unique, correct):
    # updates score
    score += unique*5
    score -= (4-correct)*2
    return score

def game():
    # game function
    num = str(generate())
    target = convert_to_list(num)
    score = 0
    final = 0   # the score once all 4 digits are guessed
    won = False
    already_guessed = []
    for i in range(10):
        print('Turns remaining:', 10-i)
        x = str(input('Guess the number : '))
        guess = convert_to_list(x)
        while(len(guess) != 4):     # checks 4 digit or not
            print('Enter a 4-digit number only')
            x = str(input('Guess the number : '))
            guess = convert_to_list(x)
        g_clone = guess.copy()
        if guess==target:
            print('All digits in the correct place.\nYou have won the game!!')
            won = True
        correct = get_correct_list(g_clone, target) 
        unique_guess = get_unique_guesses(correct.copy(), already_guessed)
        already_guessed = correct.copy()
        score = score_update(score, unique_guess, len(already_guessed))
        if won:
            print('Your Score:', final if final > 0 else score)
            break
        else:
            position = check_position(guess, target, correct)
            if position[0]==4:
                final = score
            print(len(correct),'digits:', correct, 'guessed correctly.')
            if position[0] >= position[1]:
                print(position[0], 'in the correct position.')
            else:
                print(position[1], 'in the wrong position.')
    if not won:
        print('You lost :(\nCorrect answer was', num)
    ch = str(input('Play Again? (y/n) '))
    if ch == 'y':
        return True
    else:
        return False

choice = True
while choice:
    choice = game()
print('Thanks for playing!')