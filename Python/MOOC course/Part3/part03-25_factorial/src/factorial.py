# Write your solution here
while True:
    number = int(input("Please type in a number:"))
    if number <= 0:
        print("Thanks and bye!")
        break
    else:
        temp = number
        factorial = number
        while temp > 1:
            factorial *= temp - 1
            temp -= 1
        print(f"The factorial of the number {number} is {factorial}")