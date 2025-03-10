# Write your solution here
counter = 0
positive_counter = 0
negative_counter = 0
sum = 0
print("Please type in integer numbers. Type in 0 to finish.")
while True:
    number = int(input("Number:"))
    if number != 0:
        counter += 1
        sum += number
        if number < 0:
            negative_counter += 1
        else:
            positive_counter += 1
    else:
        mean = sum / counter
        print("Numbers typed in", counter)
        print("The sum of the numbers is", sum)
        print("The mean of the numbers is", mean)
        print("Positive numbers", positive_counter)
        print("Negative numbers", negative_counter)
        break
