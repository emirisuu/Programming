# Write your solution here
sentence = input("Please type in a sentence:")
while len(sentence) > 0:
    index = sentence.find(" ")
    print(sentence[0])
    if index == -1:
        break
    sentence = sentence[index + 1:]