# Write your solution here
string = input("Please type in a string:")
substring = input("Please type in a substring:")
index = string.find(substring)
length = len(string)
if index == -1:
    print("The substring does not occur twice in the string.")
else:
    string = string[index + len(substring):]
    length = length - len(string)
    index = string.find(substring)
    if index == -1:
        print("The substring does not occur twice in the string.")
    else:
        print(f"The second occurrence of the substring is at index {index + length}.")