# Write your solution here
import random

def roll(die: str):
    A = [3, 3, 3, 3, 3, 6]
    B = [2, 2, 2, 5, 5, 5]
    C = [1, 4, 4, 4, 4, 4]
    index = random.randint(0, 5)
    if die == "A":
        return A[index]
    elif die == "B":
        return B[index]
    else:
        return C[index]

def play(die1: str, die2: str, times: int):
    win1 = 0
    win2 = 0
    tie = 0
    for i in range(times):
        roll1 = roll(die1)
        roll2 = roll(die2)
        if roll1 > roll2:
            win1 += 1
        elif roll2 > roll1:
            win2 += 1
        else:
            tie += 1
    return win1, win2, tie