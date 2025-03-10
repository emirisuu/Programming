# Write your solution here
word = input("Please type in a word:")
character = input("Please type in a character:")
index = word.find(character)
while True:
    if len(word) != 0:
        index = word.find(character)
        if index != -1:
            if len(word) - index >= 3:
                print(word[index:index + 3])
                word = word[index + 1:]
            else:
                break
        else:
            break
    else:
        break