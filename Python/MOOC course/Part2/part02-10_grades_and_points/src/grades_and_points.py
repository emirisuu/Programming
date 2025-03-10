# Write your solution here
points = int(input("How many points [0-100]:"))
if points < 0 or points > 100:
    print("Grade: impossible!")
elif points > 0 and points < 50:
    print("Grade: fail")
elif points > 49 and points < 60:
    print("Grade: 1")
elif points > 59 and points < 70:
    print("Grade: 2")
elif points > 69 and points < 80:
    print("Grade: 3")
elif points > 79 and points < 90:
    print("Grade: 4")
else:
    print("Grade: 5")