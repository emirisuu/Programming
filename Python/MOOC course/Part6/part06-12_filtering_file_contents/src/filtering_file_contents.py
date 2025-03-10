# Write your solution here
def filter_solutions():
    correct = []
    incorrect = []
    with open("solutions.csv") as new_file:
        for line in new_file:
            line = line.replace("\n", "")
            parts = line.split(";")
            index = parts[1].find("+")

            if index >= 0:
                temp = parts[1].split("+")
                number = int(temp[0]) + int(temp[1])
            else:
                temp = parts[1].split("-")
                number = int(temp[0]) - int(temp[1])
            
            if number == int(parts[2]):
                correct.append(line)
            else:
                incorrect.append(line)

    with open("correct.csv", "w") as new_file:
        for line in correct:
            new_file.write(line + "\n")
    
    with open("incorrect.csv", "w") as new_file:
        for line in incorrect:
            new_file.write(line + "\n")