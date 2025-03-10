# Write your solution here
def store_personal_data(person: tuple):
    with open("people.csv", "w") as new_file:
        line = f"{person[0]};{person[1]};{person[2]}"
        new_file.write(line + "\n")
