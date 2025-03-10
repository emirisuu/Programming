# Write your solution here
hourly_wage = float(input("Hourly wwage:"))
hours_worked = int(input("Hours worked:"))
day = input("Day of the week:")
if day == "Sunday":
    print(f"Daily wages: {hourly_wage * hours_worked * 2} euros")
else:
    print(f"Daily wages: {hourly_wage * hours_worked} euros")