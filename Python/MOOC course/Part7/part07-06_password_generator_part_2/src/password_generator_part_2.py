# Write your solution here
import random
import string
def generate_strong_password(length: int, numbers, special_characters):
    letters = list(string.ascii_lowercase)
    all_characters = letters[:]
    if numbers:
        digits = list(string.digits)
        for i in digits:
            all_characters.append(i)
    if special_characters:
        special = ["!","?","=","+","-","(",")","#"]
        for i in special:
            all_characters.append(i)
    password = ""
    password += random.choice(letters)
    length -= 1
    if numbers:
        password += random.choice(digits)
        length -= 1
    if special_characters:
        password += random.choice(special)
        length -= 1
    for i in range(length):
        index = random.randint(0, len(all_characters) - 1)
        password += all_characters[index]
    temp = list(password)
    random.shuffle(temp)
    password = ""
    for i in temp:
        password += i
    return password

#print(generate_strong_password(3, True, False))
