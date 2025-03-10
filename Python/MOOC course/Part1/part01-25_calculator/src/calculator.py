# Write your solution here
number1 = int(input("Number 1:"))
number2 = int(input("Number 2:"))
operation = input("Operation:")
if operation == "add":
    print(f"{number1} + {number2} = {number1 + number2}")
elif operation == "multiply":
    print(f"{number1} * {number2} = {number1 * number2}")
elif operation == "subtract":
    print(f"{number1} - {number2} = {number1 - number2}")