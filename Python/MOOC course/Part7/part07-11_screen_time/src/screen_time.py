# Write your solution here
from datetime import datetime, timedelta
filename = input("Filename:")
temp = input("Starting date:")
start_date = datetime.strptime(temp, "%d.%m.%Y")
add = timedelta(days=1)
final_date = start_date
days = int(input("How many days:"))
print("Please type in screen time in minutes on each day(TV computer mobile):")
screen_time = []
for i in range(days):
    text = "Screen time " + final_date.strftime("%d.%m.%Y") + ":"
    time = input(text)
    parts = time.split(" ")
    tuple = int(parts[0]), int(parts[1]), int(parts[2])
    screen_time.append(tuple)
    final_date += add
final_date -= add
total_minutes = 0
for item in screen_time:
    temp = sum(item)
    total_minutes += temp
average_minutes = total_minutes / len(screen_time)
with open(filename, "w") as new_file:
    line = "Time period: " + start_date.strftime("%d.%m.%Y") +"-" + final_date.strftime("%d.%m.%Y")
    new_file.write(line + "\n")
    line = f"Total minutes: {total_minutes}"
    new_file.write(line + "\n")
    line = f"Average minutes: {average_minutes}"
    new_file.write(line + "\n")
    for item in screen_time:
        line = start_date.strftime("%d.%m.%Y") + f": {item[0]}/{item[1]}/{item[2]}"
        new_file.write(line + "\n")
        start_date += add