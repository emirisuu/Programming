# Write your solution here
number = int(input("Please type in a number:"))
number1 = 1
number2 = 1
while number1 <= number:
    while number2 <= number:
        print(f"{number1} x {number2} = {number1 * number2}")
        number2 += 1
    number2 = 1
    number1 += 1