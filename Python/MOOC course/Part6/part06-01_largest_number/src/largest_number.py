# write your solution here
def largest():
    numbers = []
    with open("numbers.txt") as new_file:
        for line in new_file:
            line = line.replace("\n", "")
            numbers.append(int(line))
    return max(numbers)
