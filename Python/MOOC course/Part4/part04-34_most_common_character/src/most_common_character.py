# Write your solution here
def most_common_character(string):
    max = 0
    new_list = []
    for i in string:
        new_list.append(string.count(i))
    for i in range(len(new_list)):
        if new_list[i] >= new_list[max]:
            max = i
    return string[max]