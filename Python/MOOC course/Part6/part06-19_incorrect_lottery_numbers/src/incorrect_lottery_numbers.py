# Write your solution here
def filter_incorrect():
    with open("lottery_numbers.csv") as my_file:
        with open("correct_numbers.csv", "w") as new_file:
            for line in my_file:
                line = line.replace("\n", "")
                parts = line.split(";")
                week = parts[0].split(" ")
                temp = parts[1].split(",")
                try:
                    if int(week[1]) / 1:
                        k = 0
                    if len(temp) < 7:
                        continue
                    numbers = []
                    for number in temp:
                        numbers.append(int(number))
                    for number in numbers:
                        if number < 1 or number > 39:
                            k = 1
                            break
                        if numbers.count(number) > 1:
                            k = 1
                            break     
                    if k == 1:
                        continue
                except ValueError:
                    continue
                new_file.write(line + "\n")
            