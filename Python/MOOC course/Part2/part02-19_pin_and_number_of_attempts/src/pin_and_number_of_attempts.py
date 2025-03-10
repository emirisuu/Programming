# Write your solution here
counter = 0
while True:
    pin = int(input("PIN:"))
    counter += 1
    if pin == 4321:
        if counter == 1:
            print("Correct! It only took you one single attempt!")
        else:
            print(f"Correct! It took you {counter} attempts")
        break
    else:
        print("Wrong")