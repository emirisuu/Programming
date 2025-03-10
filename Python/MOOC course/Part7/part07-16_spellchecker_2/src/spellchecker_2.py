# Write your solution here
from difflib import get_close_matches
text_input = input("Write text:")
parts = text_input.split(" ")
wordlist = []
misspelled = []

with open("wordlist.txt") as new_file:
    for line in new_file:
        line = line.replace("\n", "")
        wordlist.append(line)

for word in parts:
    if word.lower() not in wordlist:
        misspelled.append(word.lower())
        temp = f"*{word}*"
        text_input = text_input.replace(word, temp)

print(text_input)
print("suggestions:")
for word in misspelled:
    suggestions = get_close_matches(word, wordlist)
    print(f"{word}: {suggestions[0]}, {suggestions[1]}, {suggestions[2]}")
