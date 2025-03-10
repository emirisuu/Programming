# Write your solution here
number = int(input("Please type in a number:"))
temp = 1
while temp <= number:
    if number - temp >= 1:
        print(temp + 1)
        print(temp)
        temp += 2
    else:
        print(temp)
        temp += 2