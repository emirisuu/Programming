# Write your solution here
list = []
print("The list is now []")
number = 1
while True:
    choice = input("a(d)d, (r)emove or e(x)it:")
    if choice == "d":
        list.append(number)
        number += 1
        print("The list is now", list)
    elif choice == "r":
        list.pop(-1)
        number -= 1
        print("The list is now", list)
    else:
        print("Bye!")
        break