# Write your solution here
students = int(input("How many students on the course?"))
group_size = int(input("Desired group size?"))
if(students % group_size >= 1):
    groups = students // group_size + 1
else:
    groups = students // group_size
print("Number of groups formed:", groups)