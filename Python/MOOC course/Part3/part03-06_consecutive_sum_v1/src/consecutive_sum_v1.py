# Write your solution here
limit = int(input("Limit:"))
number = 1
sum = 0
while sum != limit and sum < limit:
    sum += number
    number += 1
print(sum)