# Write your solution here
list = []
while True:
    new_item = int(input("New item:"))
    if new_item == 0:
        print("Bye!")
        break
    list.append(new_item)
    print("The list now:", list)
    print("The list in order:", sorted(list))