# Write your solution here
times = int(input("How many times a week do you eat at the student cafeteria?"))
lunch_price = float(input("The price of a typical student lunch?"))
groceries_money = float(input("How much money do you spend on groceries in a week?"))
print("Average food expenditure:")
print(f"Daily: {(times * lunch_price + groceries_money) / 7} euros")
print(f"Weekly: {times * lunch_price + groceries_money} euros")