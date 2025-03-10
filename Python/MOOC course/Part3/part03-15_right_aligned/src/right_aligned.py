# Write your solution here
string = input("Please type in a string:")
line = "*" * (20 - len(string)) + string
print(line)