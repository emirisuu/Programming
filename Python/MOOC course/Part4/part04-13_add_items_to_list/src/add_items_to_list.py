# Write your solution here
list = []
items = int(input("How many items:"))
for i in range(items):
    temp = int(input(f"Item {i + 1}:"))
    list.append(temp)
print(list)