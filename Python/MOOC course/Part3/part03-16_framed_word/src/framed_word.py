# Write your solution here
word = input("Word:")
print("*" * 30)
if len(word) % 2 != 0:
    line = "*" + " " * ((28 - len(word)) // 2) + word + " " * ((29 - len(word)) // 2) + "*"
else:
    line = "*" + " " * ((28 - len(word)) // 2) + word + " " * ((28 - len(word)) // 2) + "*"
print(line)
print("*" * 30)