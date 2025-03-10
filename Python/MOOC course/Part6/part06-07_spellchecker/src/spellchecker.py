# write your solution here
text_input = input("Write text:")
parts = text_input.split(" ")
wordlist = []

with open("wordlist.txt") as new_file:
    for line in new_file:
        line = line.replace("\n", "")
        wordlist.append(line)

for word in parts:
    if word.lower() not in wordlist:
        temp = f"*{word}*"
        text_input = text_input.replace(word, temp)

print(text_input)