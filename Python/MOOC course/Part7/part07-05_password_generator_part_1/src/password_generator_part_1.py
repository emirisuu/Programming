# Write your solution here
import random
import string
def generate_password(length: int):
    letters = list(string.ascii_lowercase)
    amount = len(letters)
    password = ""
    for i in range(length):
        index = random.randint(0, amount - 1)
        password += letters[index]
    return password