# Write your solution here
user = input("Whom should I sign this to:")
filename = input("Where shall I save it:")

with open(filename, "w") as new_file:
    new_file.write(f"Hi {user}, we hope you enjoy learning Python with us! Best, Mooc.fi Team")