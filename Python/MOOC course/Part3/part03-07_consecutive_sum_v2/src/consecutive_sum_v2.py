# Write your solution here
limit = int(input("Limit:"))
number = 1
sum = 0
string = "The consecutive sum: "
while sum != limit and sum < limit:
    sum += number
    if sum >= limit:
        string += f"{number} "
    else:
        string += f"{number} + "
    number += 1
    
string += f"= {sum}"
print(string)
