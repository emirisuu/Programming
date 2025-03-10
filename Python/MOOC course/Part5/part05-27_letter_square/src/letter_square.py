# Write your solution here
abc = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
layers = int(input("Layers:"))
length = layers - 1

for i in range(length + 1):
    index = layers - 1
    string = ""
    counter = layers - i
    a = 0
    while a < length:
        string += abc[index]
        if counter < layers:
            index -= 1
            counter += 1
        a += 1
    string += abc[index]
    a = 0
    while a < length:
        if length - a <= i:
            index += 1
        string += abc[index]
        a += 1
    print(string)

for i in range(length):
    counter = length - 1 - i
    index = layers - 1
    string = ""
    a = 0
    while a < length:
        string += abc[index]
        if counter > 0:
            index -= 1
            counter -= 1
        a += 1
    string += abc[index]
    a = 0
    counter = length - 1 - i
    while a < length:
        if length - a <= counter:
            index += 1
            counter -= 1
        string += abc[index]
        a += 1
    print(string)

