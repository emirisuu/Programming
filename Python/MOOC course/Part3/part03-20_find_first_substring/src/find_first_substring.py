# Write your solution here
word = input("Please type in a word:")
character = input("Please type in a character:")
index = word.find(character)
if len(word) - index >= 3:
    print(word[index:index + 3])